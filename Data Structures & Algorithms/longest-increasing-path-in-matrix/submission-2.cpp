class Solution {
public:
    int dp[105][105];
    int longer(int i , int j , vector<vector<int>>& matrix, int prev = -1){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size() || matrix[i][j] <= prev)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int &pd = dp[i][j];
        return pd = 1 + max({
            longer(i + 1, j, matrix , matrix[i][j]) , 
            longer(i - 1, j, matrix , matrix[i][j]) , 
            longer(i, j - 1, matrix , matrix[i][j]) , 
            longer(i, j + 1, matrix , matrix[i][j]) , 
        });
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                dp[i][j] = -1;
            }
        }
        int ans = 1;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                ans = max(ans , longer(i , j , matrix));
            }
        }
        return ans;
    }
};
