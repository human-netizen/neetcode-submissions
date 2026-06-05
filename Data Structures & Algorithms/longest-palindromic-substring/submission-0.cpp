class Solution {
public:
    string longestPalindrome(string s) {
        auto palinTander = [&](this auto self , int i , int j){
            if(i < 0 || j >= s.size())return 0;
            if(s[i] != s[j])return 0;
            return 2 + self(i - 1 , j + 1);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , palinTander(i , i));
            if(i != n - 1)ans = max(ans , palinTander(i , i + 1));
        }
        return ans;
    }
};
