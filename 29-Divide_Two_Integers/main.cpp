/**
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Example 3:

Input: dividend = 0, divisor = 1
Output: 0
Example 4:

Input: dividend = 1, divisor = 1
Output: 1
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (divisor == -1 && dividend == INT_MIN) {
            return INT_MAX;
        }
        if (dividend == divisor) {
            return 1;
        }
        if (divisor == 1) {
            return dividend;
        }
        
        int ans = 0;
        long step = 0;
        long temp = 0;
        int sign = (dividend ^ divisor) > 0 ? 1 : -1;
        long dividend_ = labs(dividend);
        long divisor_ = labs(divisor);
        
        while (dividend_ >= divisor_) {
            temp = divisor_;
            step = 1;
            while ((temp << 1) <= dividend_) {
                temp <<= 1;
                step <<= 1;
            }
            ans += step;
            dividend_ -= temp;
        }
        return sign * ans;
        
    }
};


