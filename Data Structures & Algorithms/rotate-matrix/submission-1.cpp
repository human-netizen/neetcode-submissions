class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ro = matrix.size();
        int co = matrix[0].size();
        for(int i = 0 ; i < ro ; i++)   {
            for(int j = 0 ; j < co ; j++){
                int x = i , y = j;
                if(ro % 2 == 1 && i == ro/2 && i == j){
                    marix[x][y] += 5000;
                    continue;
                }
                if(matrix[x][y] > 1000)continue;
                int lastVal = matrix[x][j] + 5000;
                cout << x << " " << y << endl;
                for(int k = 0 ; k < 5 ; k++){
                    int nx = y;
                    int ny = ro - x - 1;
                    x = nx;
                    y =ny;
                    swap(lastVal , matrix[nx][ny]);
                    lastVal += 5000;
                }
            }
        }
        for(int i = 0 ; i < ro ; i++){
            for(int j = 0 ; j < co ; j++){
                matrix[i][j] -= 5000;
            }
        }

    }
};
