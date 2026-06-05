class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xo = 0;
        for(int i = 1 ; i <= nums.size() ; i++){
            xo^=i;
            xo^=nums[i - 1];
        }
        return xo;
    }
};
