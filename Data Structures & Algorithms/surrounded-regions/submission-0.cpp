class Solution {
public:

    int n , m;
    void dotter(int i , int j , vector<vector<char>>& board){
        if(i < 0 || i >= n || j < 0 || j >= m)return;
        if(board[i][j] == 'X')return;
        cout << i << " " << j << " " << board[i][j] << endl;
        board[i][j] = '.';
        dotter(i - 1, j , board);
        dotter(i + 1 , j , board);
        dotter(i , j + 1 , board);
        dotter(i , j - 1 , board);
    }
    void solve(vector<vector<char>>& board) {        
        n = board.size();
        m = board[0].size();
        for(int j = 0 ; j < m ; j++){
            dotter(0 , j , board);
            dotter(n - 1 , j , board);
        }
        for(int i = 0 ; i < n ; i++){
            dotter(i , 0 , board);
            dotter(i , m - 1 , board);
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == '.')board[i][j] = 'O';
            }
        }
    }
};
