class Solution {
public:
    vector<vector<int> > dist;
    int ans(int l1 , int l2 , string word1 , string word2){
        if(l1 < 0)return l2 + 1;
        if(l2 < 0)return l1 + 1;
        int &pd = dist[l1][l2];
        if(pd != -1)return pd;
        if(word1[l1] == word2[l2])return pd = ans(l1 - 1 , l2 - 1 , word1 , word2);
        return pd = 1 + min({ans(l1 - 1 , l2 , word1 , word2) , ans(l1 , l2 - 1 , word1 , word2) , ans(l1 - 1 , l2 - 1 , word1 , word2)});
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        dist.assign(l1 , vector<int>(l2 , -1));
        return ans(l1 - 1 , l2 - 1 , word1 , word2);
    }
};
