class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs){
            ans += to_string(int(s.size())) + ":";
            ans += s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        cout << s << endl;
        while(1){
            int num = 0;
            if(isdigit(s[i]) == 0)break;
            while(i < s.size() && s[i] != ':'){
                num*=10;
                num += (s[i] - '0');
                i++;
            }
            i++;
            cout << num << " " << i << endl;
            string str = s.substr(i , num);
            i = i + num;
            ans.push_back(str);
        }
        return ans;
        
    }
};
