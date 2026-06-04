class Solution {
public:
    vector<vector<int>>adj;
    vector<int>visited;
    void dfs(int s){
        if(visited[s])return;
        visited[s] = 1;
        for(int v : adj[s]){
            if(!visited[v])dfs(v);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n + 1);
        visited.resize(n + 1);
        for(int i = 0 ; i < edges.size() ; i++){
            u = edges[i][0];
            v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(visited[i] == 0){
                dfs(i);
                cnt++;
            }
        }
        for(int i = 1  ; i <= n ; i++){
            adj[i].clear();
            visited[i] = 0;
        }
        return cnt;
    }
};
