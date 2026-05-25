class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>pref , suff;
        int ans = 0;
        heights.push_back(0);
        for(int i = 0 ; i <= n ; i++){
            while(!pref.empty() && heights[pref.top()] > heights[i]){
                int h = heights[pref.top()];
                int width = i - pref.top();
                pref.pop();
                if(!pref.empty())width = i - pref.top() - 1;
                ans = max(ans , width * h);
            }
           
            pref.push(i);            
        }
       
        return ans;
    }
};
