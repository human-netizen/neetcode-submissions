class Solution {
public:
    string val[10];
    string valer(char n){
        int num = n - '0';
        if(num <= 6){
            num-=2;
            char ch = (num*3) + 'a';
            return string(1 , ch) + string(1 , ch + 1) + string(1 , ch + 2);
        }
        if(num == 7)return "pqrs";
        if(num == 8)return "tuv";
        if(num == 9)return "wxyz";

    }
    vector<string>ans;
    void rec(string digits , int i , string cur){
        if(i == digits.size()){
            ans.push_back(cur);
            return;
        }
        string curTo = valer(digits[i]);
        for(char c : curTo){
            rec(digits , i + 1 , cur + string(1 , c));
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return ans;
        rec(digits , 0 , "");
        return ans;
        
    }
};
