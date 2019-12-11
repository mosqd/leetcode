/**
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int count = nums.size();
        if (count == 0) {
            return 0;
        }
        if (count == 1) {
            return nums[0];
        }
        int max = INT_MIN;
        int curMax = 1;
        int curMin = 1;
        for (int i = 0; i < count; i++) {
            if (nums[i] < 0) {
                std::swap(curMax, curMin);
            }
            curMax = std::max(curMax * nums[i], nums[i]);
            curMin = std::min(curMin * nums[i], nums[i]);
            max = std::max(curMax, max);
        }
        return max;
    }
};
