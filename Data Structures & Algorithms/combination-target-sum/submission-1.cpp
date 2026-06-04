class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>cur;
        vector<vector<int>> ans;
        auto solver = [&](this auto self , int i , int rem) ->void {
            if(rem == 0){
                ans.push_back(cur);
                return;
            }
            for(int j = i ; j < nums.size() ; j++){
                if(rem - nums[j] < 0)break;
                cur.push_back(nums[j]);
                self(j , rem - nums[j]);
                cur.pop_back();
            }
        }    
        solver(0 , target);
        return ans;
    }
};
