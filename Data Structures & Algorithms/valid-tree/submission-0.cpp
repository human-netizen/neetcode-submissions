class Solution {
public:
    int parent[105];
    int par(int u){
        if(parent[u] == u)return u;
        return parent[u] = par(parent[u]);
    }
    void uni(int u , int v){
        int uu = par(u);
        int vv = par(v);
        parent[uu] = vv;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() >= n)return 0;
        for(int i = 0 ; i <= n ; i++)parent[i] = i;
        int parbe = 1;
        for(auto iv : edges){
            int x = iv[0];
            int y = iv[1];
            if(par(x) == par(y))return 0;
            uni(x , y);
        }
        return 1;
    }
};
