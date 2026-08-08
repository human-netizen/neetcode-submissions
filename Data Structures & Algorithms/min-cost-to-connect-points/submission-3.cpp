class Solution {
public:
    vector<int> dist;
    vector<int>done;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        dist.assign(len , INT_MAX);
        done.assign(len , 0);
        auto distFun = [&points](int i , int j){
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        int last = 0;
        done[0] = 1;

        int ans = 0;
        for(int i = 1 ; i < points.size() ; i++){
            int nextNode = 0;
            int dd = INT_MAX;
            for(int j = 0 ; j < points.size() ; j++){
                if(done[j])continue;
                dist[j] = min(dist[j] , distFun(last , j));
                if(dist[j] < dd){
                    dd = dist[j];
                    nextNode = j;
                }
            }
            done[nextNode] = 1;
            last = nextNode;
            ans += dd;
        }
        
        return ans;
        
    }
};
