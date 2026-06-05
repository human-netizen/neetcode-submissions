class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> up;
        int ans = 0;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            up[nums[i]] = 1;
        }
        for(auto [f , second] : up){
            if(second == 1){
                int cnt = 0;
                int first = f;
                while(up[first] == 1){
                    up[first] = 0;
                    first++;
                    cnt++;
                }
                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};
