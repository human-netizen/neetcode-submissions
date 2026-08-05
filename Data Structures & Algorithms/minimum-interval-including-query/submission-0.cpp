class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin() , intervals.end());
        vector<pair<int,int>> q;
        for(int i = 0 ; i < queries.size() ; i++){
            q.push_back({queries[i] , i});
        }
        vector<int>ans(int(queries.size()));
        sort(intervals.begin() , intervals.end());
        sort(q.begin() , q.end());
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;
        int l = 0;
        
        for(int i = 0 ; i < q.size() ; i++){
            while(l < intervals.size() && intervals[l][0] <= q[i].first){
                pq.push({intervals[l][1] - intervals[l][0] + 1 , intervals[l][0]});
                l++;
            }
            while(!pq.empty() && pq.top().first + pq.top().second - 1 < q[i].first)pq.pop();
            if(!pq.empty()){
                ans[q[i].second] = pq.top().first;
            }
            else ans[q[i].second] = -1;
        }
        return ans;

    }
};
