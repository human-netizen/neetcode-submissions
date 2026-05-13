class Solution {
public:
    string minWindow(string s, string t) {
        int limit = 'z' - 'A' + 1;
        deque<int>pos[128];
        int cnt[128] = {};

        int diff = 0;
        for(int i = 0 ; i < limit ; i++)cnt[i] = 0;
        for(char ch : t){
            cnt[ch - 'A']++;
            if(cnt[ch - 'A'] == 1)diff++;
        }

        int ans = INT_MAX;
        int st , ed;
        int cnt2[128] = {};
        int cur = 0;
        int j = 0;
        for(int i = 0 ; i < limit ; i++){
            if(cnt[i] == 0)cnt[i] = INT_MIN;
        }
        cout << diff << endl;
        for(int i = 0 ; i < s.size() && j < s.size(); i++){
            
            while(j < s.size()){
                cnt2[s[j] - 'A']++;
                if(cnt2[s[j] - 'A'] == cnt[s[j] - 'A'])cur++;
                if(cur == diff)break;
                j++;
            }
            while(j < s.size() && i <= j && ((--cnt2[s[i] - 'A']) >= cnt[s[i] - 'A'])){
                i++;
            }
            cout << i << " " << j << " " << cur << " " << diff << endl;
            if(cur == diff)cur = diff - 1;
            if(j < s.size() && j - i + 1 >= t.size() && j - i + 1 < ans){
                ans = j - i + 1;
                st = i;
            }
            j++;

        }
        cout << st << " " << ans << endl;
        if(ans == INT_MAX)return "";
        return s.substr(st , ans);
    }
};
