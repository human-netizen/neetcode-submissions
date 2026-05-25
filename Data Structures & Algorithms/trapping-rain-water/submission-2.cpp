class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int mx[n + 1] = {};
        mx[n - 1] = height[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--)mx[i] = max(mx[i + 1] , height[i]);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(height[i] == 0)continue;
            if(height[i] > mx[i + 1])continue;
            int sum = 0;
            int j = i;
            do{
                sum += height[j];
                j++;
            }while(j < n && height[j] < height[i]);
            if(j < n){
                
                ans += ((j - i) * height[i] - sum);
            }
            cout << i << " " << j << " " << sum << endl;
            i = j - 1;
        }
        return ans;
    }
};
