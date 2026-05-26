class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt[2005] = {};
        for(int v : nums){
            cnt[v + 1000]++;
        }
        vector<int>adj[1005];
        for(int i = 0 ; i < 2005 ; i++){
            if(cnt[i])adj[cnt[i]].push_back(i - 1000);
        }
        vector<int>res;
        for(int i = 1000 ; i >= 1 ; i--){
            if(res.size() == k)break;
            for(int v: adj[i])res.push_back(v);
        }
        return res;
    }
};
