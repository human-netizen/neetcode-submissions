class Solution {
public:
    string text1;
    string text2;
    vector<vector<int>>dp;
    int parbe(int len1 , int len2){
        if(len1 < 0 || len2 < 0)return 0;
        int &pd = dp[len1][len2];
        if(pd != -1)return pd;
        if(text1[len1] == text2[len2])return pd = 1 + parbe(len1 - 1 , len2 - 1);
        else return pd = max(parbe(len1 - 1 , len2) , parbe(len1 , len2 - 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        this->text1 = text1;
        this->text2 = text2;
        dp.assign(len1 , vector<int>(len2 , -1));
        return parbe(len1 - 1 , len2 - 1);
    }
};
