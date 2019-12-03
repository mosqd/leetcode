/**
You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[1][n] = n
        // dp[k][n] = max(dp[k-1][x-1], dp[k][n-x]) + 1
        if (k <= 0 || n <= 0) {
            return 0;
        }
        int **dp = new int*[k+1];
        int i = 0;
        for (; i <= k; i++) {
            dp[i] = new int[n+1]();
        }
        for (i = 1; i <= n; i++) {
            dp[1][i] = i;
        }
        for (i = 2; i <= k; i++) {
            dp[i][1] = 1;
        }
        /**
        if (n >= 2) {
            for (i = 2; i <= k; i++) {
                dp[i][2] = 2;
            }
        }
        if (n >= 3) {
            for (i = 2; i <= k; i++) {
                dp[i][3] = 2;
            }
        }
        */
        int j = 0;
        int x = 0;
        int low = 0;
        int high = 0;
        int t1 = 0;
        int t2 = 0;
        for (i = 2; i <= k; i++) {
            for (j = 2; j <= n; j++) {
                low = 1;
                high = j;
                while (low+1 < high) {
                    x = (low+high)/2;
                    t1 = dp[i-1][x-1];
                    t2 = dp[i][j-x];
                    if (t1 < t2) {
                        low = x;
                    } else if (t1 > t2) {
                        high = x;
                    } else {
                        low = high = x;
                    }
                }
                dp[i][j] = 1 + std::min(std::max(dp[i-1][low-1], dp[i][j-low]),
                        std::max(dp[i-1][high-1], dp[i][j-high]));
            }
        }
        return dp[k][n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int K = stringToInteger(line);
        getline(cin, line);
        int N = stringToInteger(line);
        
        int ret = Solution().superEggDrop(K, N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
