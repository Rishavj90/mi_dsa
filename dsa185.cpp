#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {}
    int i = 0;
    stack<pair<int, int>>price_stk; //{price, ith day}
    int next(int price) {
        while(!price_stk.empty() && price_stk.top().first <= price)price_stk.pop();
        int ans  = !price_stk.empty() ? i - price_stk.top().second : i+1;
        price_stk.push({price, i});
        i++;
        return ans;
    }
};

/*
The *span* of the stock's price in one day
is the maximum number of consecutive days 
(starting from that day and going backward) 
for which the stock price was less 
than or equal to the price of that day.
*/
