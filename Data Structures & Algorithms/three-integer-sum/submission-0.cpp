class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            int r = nums.size() - 1;
            if(i > 0 && nums[i] == nums[i - 1])continue;
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(j > (i + 1) && nums[j] == nums[j - 1])continue;
                while(r >= 0 && nums[j] + nums[i] + nums[r] > 0)r--;
                while(r >= 0 && nums[j] + nums[i] + nums[r] == 0){
                    if(i != r && j != r && nums[i] <= nums[j] && nums[j] <= nums[r]){

                        if(r + 1 < nums.size() && nums[r] == nums[r + 1])continue;
                        sol.push_back({nums[i] , nums[j] , nums[r]});
                    }
                    r--;
                }
            }
        }
        return sol;
    }
};
