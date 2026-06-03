class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        for(int i = 0 ; i < len / 2; i++)   {
            if(s[i] != s[len - i - 1])return 0;
        }
        return 1;
    }
};
