class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt1[26] = {};
        int cnt2[26] = {};
        int matched = 0;
        if(s1.size() > s2.size())return 0;
        for(int i = 0 ; i < s1.size() ; i++){
            int dig1 = s1[i] - 'a';
            int dig2 = s2[i] - 'a';
            cnt1[dig1]++;
            cnt2[dig2]++;
            
        }
        for(int i = 0 ; i < 26 ; i++){
            if(cnt1[i] == cnt2[i])matched++;
        }
        if(matched == 26)return 1;
        for(int i = s1.size() ; i < s2.size() ; i++){
            int prevDig = s2[i - s1.size()] - 'a';
            int newDig = s2[i] - 'a';
            if(cnt1[prevDig] == cnt2[prevDig])matched--;
            cnt2[prevDig]--;
            if(cnt1[prevDig] == cnt2[prevDig])matched++;
            cnt2[newDig]++;
            if(cnt1[newDig] == cnt2[newDig])matched++;
            else if(cnt1[newDig] + 1 == cnt2[newDig])matched--;
            cout << i << " " << matched << endl;
            if(matched == 26)return 1;
        }
        return 0;

    }
};
