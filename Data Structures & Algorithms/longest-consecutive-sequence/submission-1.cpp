class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> up;
        int ans = 1;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            up[nums[i]] = up[nums[i] + 1] + 1;
            ans = max(ans , up[nums[i]]);
        }
        return ans;
    }
};
