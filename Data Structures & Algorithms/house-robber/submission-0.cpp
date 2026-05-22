class Solution {
public:
    int dp[101][2];
    int ans(int i , int nebo , vector<int>&nums){
        if(i == nums.size())return 0;
        if(dp[i][nebo] != -1)return dp[i][nebo];
        int one = 0 , two = 0 , three = 0;
        one = nums[i] + ans(i + 1 , 0 , nums);
        two = ans(i + 1 , 0 , nums);
        three = ans(i + 1 , 1 , nums);
        if(nebo == 1)return dp[i][nebo] = max({one , two , three});
        return dp[i][nebo] = max(two , three);
    }
    int rob(vector<int>& nums) {
        for(int i = 0 ; i < 101 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                dp[i][j] = -1;
            }
        }
        return max(ans(0 , 0 , nums) , ans(0 , 1 , nums));
    }
};
