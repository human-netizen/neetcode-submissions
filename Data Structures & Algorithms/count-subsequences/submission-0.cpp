class Solution {
public:
    vector<vector<int> > dp;
    int ans(int l1 , int l2 , string& s, string& t){
        if(l2 == -1)return 1;
        if(l1 == -1)return 0;
        int &pd = dp[l1][l2];
        if(pd != -1)return pd;
        int nebo = 0 , nebona = 0;
        if(s[l1] == t[l2])nebo = ans(l1 - 1 , l2 - 1 , s , t);
        nebona = ans(l1 - 1 , l2 , s , t);
        return pd = nebo + nebona;
    }
    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        dp.assign(l1 , vector<int>(l2 , -1));
        return ans(l1 - 1 , l2 - 1 , s, t);
    }
};
