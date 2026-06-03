class Solution {
public:
    int ro;
    int co;
    
    bool exist(vector<vector<char>>& board, string word) {
        ro = board.size();
        co = board[0].size();
        auto dfs = [$](this auto self , int x , int y , int len){
            if(len == word.size())return 1;
            if(x < 0 || y < 0 || x >= ro || y >= co)return 0;
            if(board[x][y] != word[len])return 0;
            board[x][y] = '*';
            int one = dfs(x + 1 , y , len + 1);
            int two = dfs(x , y + 1 , len + 1);
            int three = dfs(x - 1 , y , len + 1);
            int four = dfs(x , y - 1 , len + 1);
            board[x][y] = word[len];
            return (one || two || three || four);

        }
        for(int i = 0 ; i < ro ; i++){
            for(int j = 0 ; j < co ; j++){
                int sol = dfs(i , j , word);
                if(sol == 1)return 1;
            }
        }
        return 0;
    }
};
