class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(int(s.size()) , -1);
        auto dpFinder = [&](int i) -> bool{
            cout << i << " " << dp[i] << endl;
            if(dp[i] != -1)return dp[i];
            if(i == s.size())return 1;
            for(int j = 0 ; j < wordDict.size() ; j++){
                int match = 1;
                if(wordDict[j].size() + i <= s.size())
                for(int k = 0 ; k < wordDict[j].size() ; k++){
                    if(wordDict[j][k] != s[k + i]){
                        match = 0;
                        cout << j << " " << i << " " << k << endl;
                        cout << wordDict[j][k] << " " << s[k + 1] << endl;
                        break;
                    }
                }
                if(match)dp[i] = self(i + wordDict[j].size());
                if(dp[i] == 1)return 1;
            }
            return 0;
        };
        return dpFinder(0);
    }
};
