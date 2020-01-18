/**
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            if (nums[0] != 1) {
                return 1;
            }
            return 2;
        }
        int index = 0;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            index = nums[i];
            while (index != INT_MAX && index > 0) {
                index -= 1;
                if (index >= n) {
                    break;
                }
                tmp = nums[index];
                nums[index] = INT_MAX;
                index = tmp;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != INT_MAX) {
                return i+1;
            }
        }
        return n+1;
    }
};
