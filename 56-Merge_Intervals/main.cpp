/**
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals.size() == 1) {
            return intervals;
        }
        int n = intervals.size();
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] < v2[0]) {
                return true;
            } else if (v1[0] > v2[0]) {
                return false;
            } else {
                return v1[1] < v2[1];
            }
        };
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        vector<int> v(2, 0);
        v[0] = intervals[0][0];
        v[1] = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= v[1] && intervals[i][1] > v[1]) {
                v[1] = intervals[i][1];
                continue;
            }
            if (intervals[i][0] > v[1]) {
                ans.push_back(v);
                v[0] = intervals[i][0];
                v[1] = intervals[i][1];
            }
        }
        ans.push_back(v);
        return ans;
    }
};
