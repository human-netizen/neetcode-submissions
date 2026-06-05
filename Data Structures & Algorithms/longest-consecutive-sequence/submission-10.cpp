class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> up;
        int ans = 0;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            up[nums[i]] = 1;
        }
        for(int f : nums){
            //cout << f << ":" << second << endl;
            if(up[f] == 1){
                int cnt = 0;
                int first = f;
                int last = f - 1;
                while(up[first] == 1){
                    up[first] = 0;
                    cout << first << " " ;
                    first++;
                    cnt++;
                }
                while(up[last] == 1){
                    up[last] = 0;
                    cout << last << " " ;
                    last--;
                    cnt++;
                }
                cout << endl;
                cout << f << " " << first << " " << last << endl;
                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};
