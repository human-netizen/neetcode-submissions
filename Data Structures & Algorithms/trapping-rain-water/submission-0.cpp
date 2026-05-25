class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(height[i] == 0)continue;
            int sum = height[i];
            int j = i + 1;
            while(j < n && height[j] < height[i]){
                sum += height[j];
                j++;
            }
            if(j < n){
                cout << i << " " << j <<" " << sum << endl;
                ans += ((j - i) * height[i] - sum);
            }
            i = j - 1;
        }
        return ans;
    }
};
