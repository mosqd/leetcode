/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            auto search = m.find(target-nums[i]);
            if (search == m.end()) {
                m[nums[i]] = i;
                continue;
            }
            ans.push_back(search->second);
            ans.push_back(i);
            return ans;
        }
        return ans;
    }
};

/**
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
*/
