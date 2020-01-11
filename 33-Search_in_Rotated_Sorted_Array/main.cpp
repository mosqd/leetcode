/**
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int pivot = 0;
        int left = 0, right = nums.size()-1;
        if (nums[left] < nums[right] || right == 0) {
            return 0;
        }
        while (left <= right) {
            pivot = (left + right) / 2;
            if (nums[pivot] > nums[pivot+1]) {
                return pivot + 1;
            } else {
                if (nums[pivot] < nums[0]) {
                    right = pivot - 1;
                } else {
                    left = pivot + 1;
                }
            }
        }
        return 0;
    }
    int bsearch(vector<int>& nums, int left, int right, int target) {
        if (target < nums[left] || target > nums[right]) {
            return -1;
        }
        int pivot = 0;
        while (left <= right) {
            pivot = (left + right) / 2;
            if (nums[pivot] > target) {
                right = pivot - 1;
            } else if (nums[pivot] < target) {
                left = pivot + 1;
            } else {
                return pivot;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int pivot = findPivot(nums);
        if (pivot == 0) {
            return bsearch(nums, 0, nums.size()-1, target);
        }
        if (target >= nums[0]) {
            return bsearch(nums, 0, pivot-1, target);
        }
        return bsearch(nums, pivot, nums.size()-1, target);
    }
};
