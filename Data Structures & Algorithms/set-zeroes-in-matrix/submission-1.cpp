class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(matrix[i][j] == 0)matrix[i][j] = -2;
                else if(j && (matrix[i][j - 1] == -2 || matrix[i][j - 1] == -1))matrix[i][j] = -1;
            }
            for(int j = col - 1 ; j >= 0 ; j--){                
                if(matrix[i][j] >=1 && j + 1 < col && (matrix[i][j + 1] == -1 || matrix[i][j + 1] == -2))matrix[i][j] = -1;
            }
        }
        for(int j = 0 ; j < col ; j++){
            for(int i = 0 ; i < row ; i++){
                if(matrix[i][j] >= 1 && i && (matrix[i - 1][j] == -2 || matrix[i - 1][j] == -3))matrix[i][j] = -3;
            }
            for(int i = row - 1 ; i >= 0 ; i--){
                if(matrix[i][j] >= 1 && i + 1 < row && (matrix[i + 1][j] == -2 || matrix[i + 1][j] == -3))matrix[i][j] = -3;
            }
        }
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(matrix[i][j] < 0)matrix[i][j] = 0; 
            }
        }
        
    }
};
