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
                int last = f - 1;
                while(up[first] == 1){
                    up[first] = 0;
                    first++;
                    cnt++;
                }
                while(up[last] == 1){
                    up[last] = 0;
                    last--;
                    cnt++;
                }
                cout << f << " " << first << " " << last << endl;
                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};
