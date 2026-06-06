class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(int(s.size()) , -1);
        auto dpFinder = [&](this auto self , int i) -> bool{
            if(i == s.size())return 1;
            if(dp[i] != -1)return dp[i];
            for(int j = 0 ; j < wordDict.size() ; j++){
                int match = 1;
                if(wordDict[j].size() + i <= s.size())
                for(int k = 0 ; k < wordDict[j].size() ; k++){
                    if(wordDict[j][k] != s[k + i]){
                        match = 0;
                        break;
                    }
                }
                else match = 0;
                if(match)dp[i] = self(i + wordDict[j].size());
                if(dp[i] == 1)return 1;
            }
            return 0;
        };
        return dpFinder(0);
    }
};
