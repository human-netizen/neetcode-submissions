class Solution {
public:
    int dp[101][2];
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return num[0];
        for(int i = 0 ; i < 101 ; i++)dp[i][0] = dp[i][1] = -1;
        auto ans = [&](this auto self , int i , int oneNewaHoise){
            if(i >= n)return 0;
            if(oneNewaHoise && i == (n - 1))return 0;
            int &pd = dp[i][oneNewaHoise];
            if(pd != -1)return pd;
            int nebo = nums[i] + self(i + 2 , oneNewaHoise);
            int nebona = self(i + 1 , oneNewaHoise);
            return pd = max(nebo , nebona);
        };
        return max(ans(0 , 1) , ans(1 , 0));
        //return 1;

    }
};
