class Solution {
public:
    vector<vector<int>> dist;
    vector<int>parent;
    int findPar(int u){
        if(u == parent[u])return u;
        return parent[u] = findPar(parent[u]);
    }
    void _union(int u , int v){
        int p1 = findPar(u);
        int p2 = findPar(v);
        if(p1 == p2)return;
        parent[p1] = p2;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        dist.assign(len , vector<int>(len , INT_MAX));
        parent.resize(len);
        for(int i = 0 ; i < len ; i++)parent[i] = i ;
        auto distFun = [&points](int i , int j){
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> >> , greater<pair<int,pair<int,int> >> > pq;
        for(int i = 0 ; i < points.size() ; i++){
            for(int j = 0 ; j < points.size() ; j++){
                if(i == j)continue;
                dist[i][j] = distFun(i , j);
                pq.push({dist[i][j] , {i , j}});
            }
        }
        int ans = 0;
        while(!pq.empty()){
            auto [d , p] = pq.top();pq.pop();
            auto [i , j] = p;
            if(findPar(i) != findPar(j)){
                _union(i , j);
                ans += d;
            }
        }
        return ans;
        
    }
};
