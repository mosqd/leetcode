/**
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0 || sz == 1) {
            return;
        }
        int i0 = -1;
        int i = 0;
        for (; i < sz; i++) {
            if (nums[i] == 0 && i0 == -1) {
                i0 = i;
                continue;
            }
            if (nums[i] && i0 != -1) {
                std::swap(nums[i], nums[i0]);
                i0 = nums[i0+1] == 0 ? i0+1 : i;
            }
        }
    }
};

/**
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0 || sz == 1) {
            return;
        }
        int i0 = 0;
        int i = 0;
        for (; i < sz; i++) {
            if (nums[i] != 0) {
                nums[i0++] = nums[i];
            }
        }
        while (i0 < sz) {
            nums[i0++] = 0;
        }
    }
};
 */
