class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(char ch = 'A' ; ch <= 'Z' ; ch++){
            deque<char>dq;
            int temp = 0;
            for(int i = 0 ; i < s.size() ; i++){
                if(s[i] == ch)dq.push_back(s[i]);
                else{
                    if(temp < k){
                        temp++;
                        dq.push_back('*');
                    }
                    else{
                        while(!dq.empty() && dq.front() == ch)dq.pop_front();
                        while(!dq.empty() && dq.front() == '*'){
                            temp--;
                            dq.pop_front();
                        }
                    }
                }
                ans = max(ans , int(dq.size()));
            }
        }
        return ans;
    }
    
};
