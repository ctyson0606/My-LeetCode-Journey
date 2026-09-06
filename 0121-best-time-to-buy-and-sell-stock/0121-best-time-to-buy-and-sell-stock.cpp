class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int idx = 1;
        int n = prices.size();
        int maxPrice = 0;
        while(idx < n){
            if(prices[idx] < minPrice){
                minPrice = prices[idx];
            }
            else{
                if(maxPrice < (prices[idx] - minPrice)){
                    maxPrice = prices[idx] - minPrice;
                }
            }
            idx++;
        }

        return maxPrice;
    }
};