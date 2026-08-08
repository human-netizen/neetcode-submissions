class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int> > > adj;
        adj.resize(n + 1);
        for(auto vec : times){
            auto [ui , vi , ti] = tuple{vec[0] , vec[1] , vec[2]};
            adj[ui].push_back({vi , ti});
        }
        vector<int>dist;
        dist.resize(n + 1);
        fill(dist.begin() , dist.end() , INT_MAX);
        dist[k] = 0;
        dist[0] = 0;
        priority_queue<pair<int,int>  , vector<pair<int,int> >  , greater<pair<int,int> > > pq;
        pq.push({0 , k});
        while(!pq.empty()){
            auto [d , ui] = pq.top();pq.pop();
            for(auto [vi , ti] : adj[ui]){
                if(dist[ui] + ti < dist[vi]){
                    dist[vi] = dist[ui] + ti;
                    pq.push({dist[vi] , vi});
                }
            }
        }
        int mx = *max_element(dist.begin() , dist.end());
        return (mx == INT_MAX) ? -1 : mx;
        
    }
};
