class Solution {
public:
vector<int> dp = vector<int>(100, -1);
    int ans(int i , string s){
        if(i == s.size())return 1;
        if(s[i] == '0'){
            return 0;
        }
        int one = ans(i + 1 , s);
        int two = 0;
        if(i + 1 < s.size()){
            int num = stoi(s.substr(i , 2));
            if(num <= 26)two = ans(i + 2 , s);
        }
        return dp[i] = one + two;
    }
    int numDecodings(string s) {
        return ans(0 , s);
    }
};
