class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_price = prices[0]; // minimum price before day j

        for(int j = 1; j < n; j++) {
            // The maximum profit if sell on day j is price[j] - min of the prices prices[0...j)
            auto p = prices[j] - min_price;
            if (p > max_profit)
                max_profit = p;

            if (prices[j] < min_price)
                min_price = prices[j];
        }
        return max_profit;
    }
};
