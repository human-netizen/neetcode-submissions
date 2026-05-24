class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int firstRowZero = 0;
        for(int j = 0 ; j < col ; j++){
            if(matrix[0][j] == 0)firstRowZero = 1;
        }
        for(int i = 1 ; i < row ; i++){
            
            int isZero = 0;
            for(int j = 0 ; j < col ; j++){

                if(matrix[i][j] == 0){
                    isZero = 1;
                    matrix[0][j] = 0;
                }
              
              
            }
              if(isZero == 1){
                    for(int j = 0 ; j < col ; j++)matrix[i][j] = 0;
                }
        } 
        for(int j = 0 ; j < col ; j++){
            if(matrix[0][j] == 0){
                for(int i = 0 ; i < row ; i++)matrix[i][j] = 0;
            }
        }
        if(firstRowZero)
            for(int j = 0 ; j < col ; j++)matrix[0][j] = 0;
        
    }
};
