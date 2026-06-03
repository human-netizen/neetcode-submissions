class Solution {
public:
    int edge[26][26];
    int done[26] = {};
    int exist[26] = {};
    int visited[26] = {};
    string ans;
    
    string foreignDictionary(vector<string>& words) {
        for(int i = 0 ; i < 26 ; i++)done[i] = 0 , exist[i] = 0;
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < 26 ; j++){
                edge[i][j] = 0;
            }
        }
        int parbe = 1;
        for(int i = 0 ; i < words.size() ; i++){
            
            for(char c : words[i])exist[c - 'a'] = 1;
        }
        for(int i = 1 ; i < words.size() ; i++){
            int f = 0;
            while(f < min(words[i - 1].size() , words[i].size())){
                if(words[i - 1][f] != words[i][f])break;
                f++;
            }
            if(f == words[i].size() && words[i - 1].size() > words[i].size()){
                parbe = 0;
                break;
            }
            if(f == min(words[i - 1].size() , words[i].size()))continue;
            cout << words[i - 1] << " " << " " << words[i] << " " << f << endl;
            int fir = words[i - 1][f] - 'a';
            int sec = words[i][f] - 'a';
            edge[fir][sec]++;
            cout << char(fir + 'a') << " " << char(sec + 'a') << endl;
            if(edge[fir][sec] == 1)done[sec]++;   
        }
        queue<int>q;
        for(int i = 0 ; i < 26 ; i++){
            if(exist[i] && done[i] == 0)q.push(i);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans += string(1 , 'a' + u);
            for(int i = 0 ; i < 26 ; i++){
                if(edge[u][i]){
                    done[i]--;
                    if(done[i] == 0)q.push(i);
                }
            }
        }
        for(int i = 0 ; i < 26 ; i++){
            if(done[i] != 0){
                parbe = 0;
                cout << (char)(i + 'a');
            }
        }
        if(parbe)return ans;
        return ""; 
    }
};
