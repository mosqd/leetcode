/**
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        if (sz == 0 || sz == 1) {
            return 0;
        }
        int left = 0;
        int right = sz-1;
        int lmax = height[left];
        int rmax = height[right];
        int sum = 0;
        while (left <= right) {
            lmax = std::max(lmax, height[left]);
            rmax = std::max(rmax, height[right]);

            sum += lmax < rmax ? lmax - height[left++] : rmax - height[right--];
        }
        return sum;
    }
};
