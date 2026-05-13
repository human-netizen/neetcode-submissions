class Solution {
public:
    string minWindow(string s, string t) {
        int limit = 'z' - 'A' + 1;
        deque<int>pos[limit];
        int cnt[limit] = {};

        for(int i = 0 ; i < s.size() ; i++){
            pos[s[i] - 'A'].push_back(i);
        }
        for(char ch : t){
            cnt[ch - 'A']++;
        }
        int ans = INT_MAX;
        int st , ed;
        for(int i = 0 ; i < s.size() ; i++){
            int mx = -1;
            for(int al = 0 ; al < limit ; al++){
                if(cnt[al] == 0)continue;
                int temp = INT_MAX;
                if(pos[al].size() >= cnt[al])temp = pos[al][cnt[al] - 1];
                mx = max(mx , temp);
            }
            if(mx == INT_MAX)break;
            if(mx - i + 1 < ans){
                ans = mx - i + 1;
                st = i ;
            }
            ans = min(ans , mx - i + 1);
            pos[s[i] - 'A'].pop_front();
        }
        cout << st << " " << ans << endl;
        if(ans == INT_MAX)return "";
        return s.substr(st , ans);
    }
};
