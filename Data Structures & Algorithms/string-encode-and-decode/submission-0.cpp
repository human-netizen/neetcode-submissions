class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs){
            ans += s;
            int rem = 250 - s.size();
            ans += string(rem , ' ');
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0 ; i < s.size() / 250 ; i++){
            string str = (s.substr(i * 250 , 250));
            while(!str.empty() && str.back() == ' ')str.pop_back();
            ans.push_back(str);
        }
        return ans;
    }
};
