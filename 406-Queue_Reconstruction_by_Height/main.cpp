/**
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 

Accepted
107,359
Submissions
170,944
 */

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        if (n <= 1) {
            return people;
        }
        vector<vector<int>> ans(n);
        std::sort(people.begin(), people.end());
        int k = 0;
        for (auto& p : people) {
            k = p[1];
            for (int i = 0; i < n; i++) {
                if (k > 0) {
                    if (ans[i].size() == 0 || ans[i][0] == p[0]) {
                        k--;
                    }
                    continue;
                }
                if (ans[i].size() == 0) {
                    ans[i] = p;
                    break;
                }
            }

        }
        return ans;
    }
};
