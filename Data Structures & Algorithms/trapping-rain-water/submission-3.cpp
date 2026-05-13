class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int suff[n + 1] = {};
        int pref[n + 1] = {};
        suff[n - 1] = height[n - 1];
        pref[0] = height[0];
        for(int i = 1 ; i < n ; i++){
            pref[i] = max(pref[i - 1] , height[i]);
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            suff[i] = max(suff[i + 1] , height[i]);
        }
        int ans = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            ans += max(0 , (min(pref[i - 1] , suff[i + 1]) - height[i]));
        }
        
        return ans;
    }
};
