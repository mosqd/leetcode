/**
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int sz = nums.size();
        int i = 0;
        int val = 0;
        int index = 0;
        for (; i < sz; i++) {
            index = nums[i];
            while (index && nums[index-1] != 0) {
                val = nums[index-1];
                nums[index-1] = 0;
                index = val;
            }
        }
        vector<int> ans;
        for (i = 0; i < sz; i++) {
            if (nums[i] != 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
