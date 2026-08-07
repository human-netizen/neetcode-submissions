typedef long long ll;
class Solution {
public:
    int chunk(vector<int>&nums , int lo , int hi){
        ll ans = 1;
       ll cur = 1;
       for(int i = lo ; i <= hi ; i++){
            if(cur > 0){
                cur *= nums[i];
            }
            ans *= nums[i];
       } 
       ll prev = 1;
       for(int i = hi; i >= lo ; i--){
            if(prev > 0){
                prev *= nums[i];
            }
       }
       //return 1;
       if(hi - lo + 1 == 1)return nums[0];
       if(ans > 0)return ans;
       return ans / (max(prev , cur));
    }
    int maxProduct(vector<int>& nums) {
        int lo = 0;
        int ans = INT_MIN;
        while(lo < nums.size()){   
            if(nums[lo] == 0)     ans = max(ans , 0);
            while(lo < nums.size() && nums[lo] == 0)lo++;
            int hi = lo;
            while(hi < nums.size() && nums[hi] != 0)hi++;
            ans = max(ans , chunk(nums , lo , hi - 1));
            lo = hi;
        }
        return ans;
    }
};
