class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int ro = grid.size();
        if(ro == 0)return 0;
        int co = grid[0].size();
        auto dfs = [&](this auto self , int i , int j)-> void{
            if(i < 0 || j < 0 || i >= ro || j >= co)return;
            if(grid[i][j] == '0')return;
            grid[i][j] = '0';
            self(i + 1 , j);
            self(i , j + 1);
            self(i - 1 , j);
            self(i + 1  , j);
        };
        int cnt = 0;
        for(int i = 0 ; i < ro ; i++){
            for(int j = 0 ; j < co ; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i  , j);
                    for(int i = 0 ; i < ro ; i++){
                        for(int j = 0 ; j < co ; j++){
                            cout << grid[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
            }
        }
        return cnt;
    }
};
