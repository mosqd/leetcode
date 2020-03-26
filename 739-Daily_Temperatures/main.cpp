/**
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        if (n == 1) {
            return ans;
        }
        stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && T[s.top()] <= T[i]) s.pop();
            ans[i] = s.empty() ? 0 : s.top()-i;
            s.push(i);
        }
        return ans;
    }
};

/**
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        if (n == 1) {
            return ans;
        }
        vector<int> hash(101, 30001);
        for (int i = n-1; i >= 0; i--) {
            int min = 30001;
            for (int j = T[i]+1; j <= 100; j++) {
                if (hash[j] < min) {
                    min = hash[j];
                }
            }
            if (min < 30001) {
                ans[i] = min - i;
            }
            hash[T[i]] = i;
        }
        return ans;
    }
};
*/
