class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {};
        for(char ch : s)cnt[ch - 'a']++;
        if(s.size() != t.size())return 0;
        for(char ch : t){
            cnt[ch - 'a']--;
            if(cnt[ch - 'a'] == -1)return 0;
        }
        return 1;

    }
};
