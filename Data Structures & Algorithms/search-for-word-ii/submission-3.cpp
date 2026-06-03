class Solution {
public:
    struct TrieNode{
        TrieNode* ara[26];
    };
    TrieNode* root;
    vector<vector<pair<int,int> >>dirs;
    int ro;
    int co;
    int xara[4] = {-1 , 0 , 1 , 0};
    int yara[4] = {0 , -1 , 0 , 1};
    void add(string& s){
        TrieNode* temp = root;
        for(char c : s){
            if(temp->ara[c - 'a'] == NULL)temp->ara[c - 'a'] = new TrieNode();
            temp = temp->ara[c - 'a'];
        }
    }
    bool search(string s){
        cout << endl << s << endl;
        TrieNode* temp = root;
        for(char c : s){
            cout << c << " " ;
            if(temp->ara[c - 'a'] == NULL)return 0;
            temp = temp->ara[c - 'a'];
        }
        return 1;
    }
    int visited[25][25];

    void back(int x , int y , vector<pair<int,int>>res){
        if(res.size() == 9){
            dirs.push_back(res);
            return;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + xara[i];
            int ny = y + yara[i];
            if(nx < 0 || ny < 0 || visited[nx][ny])continue;
            visited[nx][ny] = 1;
            res.push_back({xara[i] , yara[i]});
            back(nx , ny , res);
            res.pop_back();
            visited[nx][ny] = 0;
        }
    }     
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        cout << "HI" << endl;
        root = new TrieNode();
        ro = board.size();
        co = board[0].size();   
        for(int i = 0 ; i < 25 ; i++){
            for(int j = 0 ; j < 25 ; j++){
                visited[i][j] = 0;
            }
        }
        vector<pair<int,int> > res;
        back(10 , 10 , res);
        for(int i = 0 ; i < ro ; i++){
            for(int j = 0 ; j < co ; j++){
                    cout << i << " " << j << endl;
                    for(auto iv : dirs){
                        int cx = i;
                        int cy = j;
                        string s = string(1 , board[i][j]);
                        
                        for(auto vi : iv){
                            cx += vi.first;
                            cy += vi.second;
                            if(cx < 0 || cy < 0 || cx >= ro || cy >= co)break;
                            s += string(1 , board[cx][cy]);                        
                        }


                        add(s);
                    }
                }
            }
        
        vector<string>vec;
        for(string s : words){
            if(search(s))vec.push_back(s);
        }
        return vec;

    }
};
