class Solution {
public:
    vector<int> adj[105];
    int disc[105];
    int low[105];
    int visited[105];
    int par[105];
    void dfs(int u, int d = 0, int p = -1){
        disc[u] = low[u] = d;
        d++;
        visited[u] = 1;
        for(int v : adj[u]){
            if(v == p)continue;
            if(visited[v] == 0)
            {
                dfs(v , d , u);
                par[v] = u;
                low[u] = min(low[u] , low[v]);
            }
            else low[u] = min(low[u] , disc[v]);
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0] , b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0 ; i < 105 ; i++){
            low[i] = disc[i] = INT_MAX;
            visited[i] = 0;
        }
        dfs(1);
        vector<int>bri;
        for(int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0] , b = edges[i][1];
            bool swapped = 0;
            if(par[b] != a){
                swap(a , b);
                swapped = 1;
            }
            cout << a << " " << b << " " << disc[a] << " " << low[b] << endl;
            if(low[b] <= disc[a]){
                bri.clear();
                if(swapped)swap(a , b);
                bri.push_back(a);
                bri.push_back(b);
            }
        }
        return bri;

    }
};
