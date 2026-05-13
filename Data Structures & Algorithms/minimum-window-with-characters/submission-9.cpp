class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt, cnt2;
        int diff = 0;

        for (char ch : t) {
            if (cnt[ch]++ == 0) diff++;
        }

        int ans = INT_MAX, st = 0;
        int cur = 0, j = 0;

        for (int i = 0; i < s.size() && j <= s.size(); i++) {
            while (j < s.size() && cur < diff) {
                if (++cnt2[s[j]] == cnt[s[j]]) cur++;
                j++;
            }
            if (cur == diff && j - i < ans) {
                ans = j - i;
                st = i;
            }
            if (--cnt2[s[i]] < cnt[s[i]]) cur--;
        }

        return ans == INT_MAX ? "" : s.substr(st, ans);
    }
};