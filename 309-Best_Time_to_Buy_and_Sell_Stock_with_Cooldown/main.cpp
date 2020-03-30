/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int rest = 0, buy = 0, sell = 0;
        int preRest = 0, preBuy = -prices[0];
        for (int i = 1; i < n; i++) {
            rest = std::max(preRest, sell);
            buy = std::max(preBuy, preRest-prices[i]);
            sell = preBuy + prices[i];
            preRest = rest;
            preBuy = buy;
        }
        return std::max(preRest, sell);
    }
};
