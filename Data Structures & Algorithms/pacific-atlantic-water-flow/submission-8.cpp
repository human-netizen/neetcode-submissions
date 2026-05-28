class Solution {
public:
    int gr[101][101][2];
    int isVisited[101][101];
    int ro , co;
    vector<vector<int>> heights;
    int x[4] = {-1 , 0 , 1 , 0};
    int y[4] = {0 , -1 , 0 , 1};
    void dfs(int i , int j){
        if(isVisited[i][j])return;
        isVisited[i][j] = 1;
        if(i == 0 || j == 0)gr[i][j][0] = 1;
        if(i == (ro - 1) || j == (co - 1))gr[i][j][1] = 1;

        if(i == 0 && j == (co - 1))gr[i][j][1] = 1;
        if(j == 0 && i == (ro - 1))gr[i][j][0] = 1;
        cout << "main " << i << " " << j << endl;
        for(int l = 0 ; l < 4 ; l++){
            int nx = i + x[l];
            int ny = j + y[l];
            if(nx < 0 || nx >= ro || ny < 0 || ny >= co)continue;
                        cout << i << " " << j << "___" << nx << " " << ny << endl;
            
            if(heights[i][j] >= heights[nx][ny]){                
                dfs(nx , ny);
                cout << i << " " << j << "___" << nx << " " << ny << endl;
                cout << gr[nx][ny][0] << " " << gr[nx][ny][1] << endl;
                gr[i][j][0]|=gr[nx][ny][0];
                gr[i][j][1]|=gr[nx][ny][1];

                if(heights[i][j] == heights[nx][ny]){
                    gr[nx][ny][0]|=gr[i][j][0];
                    gr[nx][ny][1]|=gr[i][j][1];
                }
            }
            
        }
        //cout << i << " " << j << " " << gr[i][j][0] << " " << gr[i][j][1] << endl;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&_heights) {
        heights = _heights;
        ro = heights.size();
        co = heights[0].size();
        for(int i = 0 ; i <= 100 ; i++){
            for(int j = 0 ; j <= 100 ; j++){
                isVisited[i][j] = 0;
                gr[i][j][0] = gr[i][j][1] = 0;
            }
        }
        for(int i = 0 ; i < ro ; i++){
            for(int j = 0 ; j < co ; j++){
                dfs(i , j);
            }
        }
        vector<vector<int>> sol;
        for(int i = 0 ; i < ro ; i++){
            for(int j = 0 ; j < co ; j++){
                if(gr[i][j][1] == 1 && gr[i][j][0] == 1)sol.push_back({i , j});
            }
        }
        return sol;
    }
};
