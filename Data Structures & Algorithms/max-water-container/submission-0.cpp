class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mxIdx = -1;
        int ans = 0;
        int n = heights.size();
        vector<int>pref(n);
        for(int i = 0 ; i < heights.size() ; i++){
            
            pref[0] = heights[i];
            if(i)pref[i] += pref[i - 1];
            if(i)
            ans = max(ans , min(heights[i] , heights[mxIdx]) * (i - mxIdx) - (pref[i - 1] - pref[mxIdx]));
            if(heights[mxIdx] < heights[i]){
                mxIdx = i;
            }
        }
        return ans;
    }
};
