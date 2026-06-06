class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n + 1);
        if(n == 0)return dp;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i / 2] + (i % 2 == 1);
        }   
        return dp;
    }
};
