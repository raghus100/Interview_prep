//
//  stock.c
//  Interview_prep
//
//  Created by ragsekar on 10/23/19.
//  Copyright © 2019 ragsekar. All rights reserved.
//

#include "main.h"

int min_of_2(int a, int b)
{
    if(a < b) return a;
    else return b;
}
int max_of_2(int a, int b)
{
    if (a > b) return a;
    else return b;
}
/*Best Time to Buy and Sell Stock I*/
int maxProfit(int* prices, int pricesSize)
{
    int cur_max_profit = 0;
    if(!prices || pricesSize <=1) return 0;
    int min_val_so_far = prices[0];
    for(int i = 1; i < pricesSize; i++) {
        if(prices[i] > min_val_so_far) {
            cur_max_profit = max_of_2(cur_max_profit,prices[i] - min_val_so_far);
        }
        min_val_so_far = min_of_2(min_val_so_far, prices[i]);
    }
    return cur_max_profit;
}

/* Best Time to Buy and Sell Stock II*/
int maxProfit2(int* prices, int pricesSize)
{
    if(!prices || pricesSize <= 1) return 0;
    int profit = 0;
    int i = 0;
    for(i = 1; i < pricesSize; i++) {
        if(prices[i-1] < prices[i])
            profit += (prices[i] - prices[i-1]);
    }
    return profit;
}

void max_profit()
{
    int prices[] = {0, 6, -3, 7};
    int size = sizeof(prices)/ sizeof(prices[0]);
    printf("Max profit for STOCK-I is :%d\n", maxProfit(prices, size));
    int prices2[] = {1,2,3,4,5};
    size = sizeof(prices2)/ sizeof(prices2[0]);
    printf("Max profit for STOCK-II is :%d\n", maxProfit2(prices2, size));
    return;
}


/*
 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 Example:

 Input: [1,2,3,0,2]
 Output: 3
 Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */


 
/*
 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most two transactions.

 Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 Example 1:

 Input: [3,3,5,0,0,3,1,4]
 Output: 6
 Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 Example 2:

 Input: [1,2,3,4,5]
 Output: 4
 Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
              engaging multiple transactions at the same time. You must sell before buying again.
 Example 3:

 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

/*
 Say you have an array for which the i-th element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most k transactions.

 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 Example 1:

 Input: [2,4,1], k = 2
 Output: 2
 Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 Example 2:

 Input: [3,2,6,5,0,3], k = 2
 Output: 7
 Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 */
 
