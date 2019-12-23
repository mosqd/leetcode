/**
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) {
            return 0;
        }
        int left = -1;
        int right = -1;
        int max = nums[0];
        int min = nums[sz-1];
        for (int i = 0; i < sz; i++) {
            max = std::max(max, nums[i]);
            min = std::min(min, nums[sz-i-1]);
            if (nums[i] < max) {
                right = i;
            }
            if (nums[sz-i-1] > min) {
                left = sz-i-1;
            }
        }
        return (left < 0 ? 0 : right - left + 1);
    }
};
