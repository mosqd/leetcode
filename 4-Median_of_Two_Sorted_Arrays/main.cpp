/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

// 1  3  6 9
// 4
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (n < m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0;
        int right = m;
        int sz = (m + n + 1) / 2;
        int i = 0;
        int j = 0;
        int maxleft = 0;
        int minright = 0;
        while (left <= right) {
            i = (left + right) / 2;
            j = sz - i;
            if (i < right && nums2[j-1] > nums1[i]) {
                left = i + 1;
            } else if (i > left && nums1[i-1] > nums2[j]) {
                right = i - 1;
            } else {
                if (i == 0) {
                    maxleft = nums2[j-1];
                } else if (j == 0) {
                    maxleft = nums1[i-1];
                } else {
                    maxleft = std::max(nums1[i-1], nums2[j-1]);
                }

                if ((m + n) % 2 == 1) {
                    return maxleft;
                }

                if (i == m)  {
                    minright = nums2[j];
                } else if (j == n) {
                    minright = nums1[i];
                } else {
                    minright = std::min(nums1[i], nums2[j]);
                }
                return (maxleft+minright)/2.0;
            }
        }
        return 0.0;
    }

};
