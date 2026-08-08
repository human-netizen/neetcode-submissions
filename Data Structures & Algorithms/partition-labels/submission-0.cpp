class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>sol;
        int n = s.size();
        vector<int>mx(26);
        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            mx[ch - 'a'] = i;
        }
        int cur = 0;
        int last = -1;
        cout << "n: " << n << endl;
        for(int i = 0 ; i < n ; i++){
            cout << "HERE" << endl;
            char ch = s[i];
            cur = max(cur , mx[ch - 'a']);
            cout << i << " " << cur << endl;
            if(cur == i){
                sol.push_back(cur - last);
                last = cur;
            }
        }

        return sol;
    }
};
