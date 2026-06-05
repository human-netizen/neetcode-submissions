class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , 
        [](Interval one , Interval two){
            if(one[0] == two[0])return one[1] < two[1];
            return one[0] < two[0];
        });   
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i++){
            if(intevals[i][0] <= ans.back()[1])ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
