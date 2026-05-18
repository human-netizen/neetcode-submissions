class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        string ans;
        for(char ch : s){
            if(ch == ']'){
                string temp;
                while(st.top() !='['){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                reverse(temp.begin() , temp.end());
                int num = 0;
                int ten = 1;
                while(!st.empty() && isdigit(st.top())){
                    num+=(ten * (st.top() - '0'));
                    st.pop();
                    ten*=10;
                }
                cout << num << " " << temp << endl;
                for(int i = 0 ;  i < num ; i++){
                    for(char ch2 : temp)st.push(ch2);
                }


            }
            else st.push(ch);

        }    
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;

    }
};