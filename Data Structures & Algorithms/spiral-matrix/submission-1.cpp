class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int top = 0 , left = 0 , right = matrix[0].size() - 1 , bottom = matrix.size() - 1;
        int row = right + 1;
        int col = bottom + 1;
        cout << row << " " << col << endl;
        while(res.size() < (row * col))
        {
            for(int i = left ; i <= right && res.size() < (row * col); i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top ; i <= bottom && res.size() < (row * col); i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            for(int i = right ; i >= left && res.size() < (row * col); i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i = bottom ; i >= top && res.size() < (row * col); i--){
                res.push_back(matrix[i][left]);
            }
            left++;
            cout << left << " " << right << " " << top << " " << bottom << endl;
        }
        return res;
    }
};
