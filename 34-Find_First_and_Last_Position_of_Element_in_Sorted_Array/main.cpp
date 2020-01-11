/**
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */

class Solution {
public:
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        if (n == 0) {
            return ans;
        }
        if (n == 1) {
            if (nums[0] == target) {
                ans[0] = 0;
                ans[1] = 0;
            }
            return ans;
        }
        int index = bsearch(nums, 0, n-1, target);
        if (index == -1) {
            return ans;
        }
        int first = index;
        int last = index;
        for (int i = index-1; i >= 0; i--) {
            if (nums[i] == target) {
                first = i;
                continue;
            }
            break;
        }
        for (int i = index+1; i < n; i++) {
            if (nums[i] == target) {
                last = i;
                continue;
            }
            break;
        }
        ans[0] = first;
        ans[1] = last;
        return ans;
    }
};
