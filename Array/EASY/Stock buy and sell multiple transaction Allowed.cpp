/*
STOCK BUY & SELL PROBLEM (Multiple Transactions)
==============================================

Problem:
-------
Given an array prices[] of size n denoting stock prices on each day, 
find the maximum profit if we can buy and sell stocks any number of times.

Constraints:
----------
- Can only sell a stock after buying it
- Cannot hold multiple stocks on any day

Approach:
--------
- Use a greedy algorithm to capture all upward price movements
- Instead of waiting for local maxima, sell whenever there's a profit
- Simply add up all positive price differences between consecutive days

Algorithm:
---------
1. Traverse prices[] from index 1 to n-1
2. Initialize profit = 0
3. If price[i] > price[i-1]:
    - Add (price[i] - price[i-1]) to profit
4. Return total profit
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maximumProfit(const vector<int>& prices) {
    int res = 0;
  
    // Keep on adding the difference between
    // adjacent when the prices a
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) 
            res += prices[i] - prices[i - 1];
    }
    
    return res;
}
