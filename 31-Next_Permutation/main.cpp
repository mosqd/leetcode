/**
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3(123) → 1,3,2(132)
3,2,1 → 1,2,3
1,1,5(115) → 1,5,1(151)
即找出第一个大于左边数的数字
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        if (n == 2) {
            std::swap(nums[0], nums[1]);
            return;
        }
        int i = n - 2;
        int tmp = 0;
        for (; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    std::swap(nums[j], nums[i]);
                    return;
                }
            }
            tmp = nums[i];
            for (int k = i + 1; k < n; k++) {
                nums[k-1] = nums[k];
            }
            nums[n-1] = tmp;
        }
    }
};
