class Solution {
public:
    vector<string> anss;
    string ans;
    void rec(int n , int cur){
        
        if(n == 0){
            if(cur == 0)anss.push_back(ans);
            return;
        }
        if(cur > 0){
            ans.push_back(')');
            rec(n - 1 , cur - 1);
            ans.pop_back();
        }
        
        ans.push_back('(');
        rec(n - 1 , cur + 1);
        ans.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        n *= 2;
        rec(n , 0);
        return anss;
    }
};
