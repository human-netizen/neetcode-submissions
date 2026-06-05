class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        auto palinTander = [&](this auto self , int i , int j) -> int{
            if(i < 0 || j >= s.size())return 0;
            if(s[i] != s[j])return 0;
            return (i == j ? 1 : 2) + self(i - 1 , j + 1);
        };
        int ans = 0;
        int curI = 0;
        for(int i = 0 ; i < n ; i++){
            int one = palinTander(i , i);
            if(one > ans){
                ans = one;
                curI = i;
            }
            if(i != n - 1){
                int two = palinTander(i , i + 1);
                if(two > ans){
                    ans = two;
                    curI = i;
                }   
            }
        }
        string sub = s.substr(curI - ans / 2 , ans);
        
        return sub;
    }
};
