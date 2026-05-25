class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxi = 10000;
        int ans[10000 + 1];
        for(int i = 1 ; i <= maxi ; i++)ans[i] = INT_MAX;
        ans[0] = 0;
        for(int i = 1 ; i <= amount ; i++){
            for(int j : coins){
                if(j > i)continue;
                if(ans[i - j] != INT_MAX)ans[i] = min({ans[i] , 1 + ans[i - j]});
            }
        }
        return (ans[amount] != INT_MAX) ? ans[amount] : -1;
    }
};
