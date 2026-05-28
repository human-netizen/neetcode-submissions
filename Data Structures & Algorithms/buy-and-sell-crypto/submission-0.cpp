class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int ans = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            ans = max(ans , prices[i] - minBuy);
            minBuy = min(minBuy , prices[i]);
        }
        return ans;
    }
};
