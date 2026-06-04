class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        
        for(int num : nums){
            auto up = st.upper_bound(num);
            if(up != st.end())st.erase(up);
            st.insert(num);
        }
        return st.size();
    }
};
