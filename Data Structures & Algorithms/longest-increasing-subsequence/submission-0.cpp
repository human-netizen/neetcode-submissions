class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[n - 1] = 1;
        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = i + 1 ; j < n ; j++){
                ans[i] = max(ans[i] , 1 + (ans[j]) * (nums[i] < nums[j]));
            }
        }
        return *max_element(ans.begin() , ans.end());

    }
};
