class Solution {
public:
    vector<vector<int>>grid;
    int n , m;
    int ans(int x , int y){
        if(x < 0 || y < 0 || x >= n || y >= m)return 0;
        if(grid[x][y] == 0)return 0;
        grid[x][y] = 0;
        return ans(x + 1 , y) + ans(x - 1 , y) + ans(x , y + 1) + ans(x , y - 1) + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        int aa = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                aa = max(aa , ans(i , j));
            }
        }
        return aa;
    }
};
