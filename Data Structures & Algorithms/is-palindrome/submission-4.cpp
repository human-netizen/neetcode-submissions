class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int n = s.size();
        while(l < r){
            while(l < n && isalnum(s[l]) == 0)l++;
            while(r >= 0 && isalnum(s[r]) == 0)r--;
            if(l < r){
                if(tolower(s[l]) != tolower(s[r]))return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
};
