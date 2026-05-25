class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(height[i] == 0)continue;
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
