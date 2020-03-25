/**
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        int letters[26] = {0};
        for (char t : tasks) {
            letters[t-'A']++;
        }
        int k = 0;
        std::sort(letters, letters+26);
        while (letters[25]) {
            k = 0;
            for (int i = 25; i >= 0; i--) {
                if (letters[i] > 0) {
                    letters[i]--;
                    k++;
                }
                if (k-1 == n) {
                    break;
                }
            }
            ans += k;
            std::sort(letters, letters+26);
            if (k <= n && letters[25] > 0) {
                ans += n - k + 1;
            }
        }
        return ans;
    }
};
