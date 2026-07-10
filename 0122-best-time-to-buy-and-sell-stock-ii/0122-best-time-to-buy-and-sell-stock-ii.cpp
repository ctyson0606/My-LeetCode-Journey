class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int profit = -1;
        int maxProfit = 0;
        for(int i = 1; i < prices.size() ; i++){
            if(prices[i] <= prices[buy]){
                buy = i;
            }
            else{}{
                profit = prices[i] - prices[buy];
                maxProfit += profit;
                buy = i;
            }
        }
        return maxProfit;
    }
};