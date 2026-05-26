class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIdx = 0;
        int cnt[257] = {};
        int mx = 1;
        cnt[s[0]]++;
        for(int i = 1 ; i < s.size() ; i++){
            cnt[s[i]]++;
            while(cnt[s[i]] > 1){
                cnt[s[lastIdx]]--;
                lastIdx++;
            }
            mx = max(mx , i - lastIdx + 1);
        }
        return mx;
    }
};
