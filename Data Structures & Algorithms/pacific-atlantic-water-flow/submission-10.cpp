class Solution {
public:
    int gr[105][105][2] = {};
    int xara[4] = {-1 , 0 , 1 , 0};
    int row;
    int col;
    int yara[4] = {0 , 1 , 0 , -1};
    void bfs(vector<vector<int>>& heights , int c){
        vector<pair<int,int> > s;
        if(c == 0){
            for(int i = 0 ; i < row ; i++)s.push_back({i , 0});
            for(int j = 0 ; j < col ; j++)s.push_back({0 , j});
        }
        else{
            for(int i = 0 ; i < row ; i++)s.push_back({i , col - 1});
            for(int j = 0 ; j < col ; j++)s.push_back({row - 1 , j});
        }
        int visited[105][105] = {};
        queue<pair<int,int> > q;
        for(auto iv : s){
            q.push(iv);
            visited[iv.first][iv.second] = 1;
        }
        while(!q.empty()){

            auto iv = q.front();q.pop();
            int x = iv.first , y = iv.second;
            //cout << x << " " << y << " " << color << endl;
            gr[x][y][c] = 1;
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + xara[i];
                int ny = y + yara[i];
                if(nx < 0 || nx >= row || ny < 0 || ny >= col || visited[nx][ny] || heights[nx][ny] < heights[x][y])continue;
                visited[nx][ny] = 1;
                q.push({nx , ny});
            }

        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();

        bfs(heights , 0);
        bfs(heights , 1);

        vector<vector<int>> res;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(gr[i][j][0] + gr[i][j][1] == 2)res.push_back({i , j});
                cout << i << " " << j << " " << gr[i][j][0] << " " << gr[i][j][1] << endl;
            }
        }
        // top of pacificAtlantic, before the bfs calls
        for(int i = 0 ;i < row ; i++){
            for(int j = 0 ; i < col ; j++){
                for(int k = 0 ; k < 2 ; k++)gr[i][j][0] = gr[i][j][1] = 0;
            }
        }
        return res;
    }
};
