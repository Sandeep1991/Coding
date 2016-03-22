/*
121. Best Time to Buy and Sell Stock
Total Accepted: 91259 Total Submissions: 255508 Difficulty: Medium

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum pr
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int profit = 0;
		int minElement = prices[0];
		for(int i=0; i<prices.size(); i++)
			{
				 profit = max(profit, prices[i]-minElement);
				 minElement = min(minElement, prices[i]);
			}
		return profit;
    }
};
