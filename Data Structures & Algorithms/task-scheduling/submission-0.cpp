class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>> pq;
        int cnt[26] = {};
        for(char ch : tasks){
            cnt[ch - 'A']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(cnt[i] != 0){
                pq.push({cnt[i] , i});
            }
        }
        int ans = 0;
        
        while(pq.size() >= n){
            vector<pair<int,int> > vec;
            for(int i = 0 ; i < n ; i++){
                if(pq.top().first - 1 > 0)
                vec.push_back({pq.top().first - 1 , pq.top().second});
                pq.pop();
            }
            int ase = 0;
            if(!pq.empty()){
                ase = 1;
                if(pq.top().first - 1 > 0)
                vec.push_back({pq.top().first - 1 , pq.top().second});
                pq.pop();
            }
            ans += (n);
            if(!vec.empty())ans++;
            for(auto iv : vec){
                pq.push(iv);
            }
        }
        for(int i = 0 ; i < 26 ; i++)cnt[i] = 0;
        cout << ans << endl;
        while(!pq.empty()){
            cnt[pq.top().second] = pq.top().first;
            cout << pq.top().second << " " << pq.top().first << endl;
            pq.pop();
        }
        while(1){
            int ase = 0;
            int aroAse = 0;
            for(int i = 0 ; i < 26 ; i++){
                if(cnt[i]){
                    cnt[i]--;
                    ase++;
                    if(cnt[i])aroAse = 1;
                }
            }
            if(aroAse == 0){
                ans += ase;
                break;
            }
            else ans += (n + 1);
        }
        return ans;
    }
};
