class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int cur = intervals.size() - 1;
        while(cur > 0){
            if(intervals[cur][1] < intervals[cur - 1][0])swap(intervals[cur] , intervals[cur - 1]);
            else break;
            cur--;
        }
        int scur = cur;
        int mx = intervals[cur][1];
        while(scur - 1 >= 0 && intervals[cur][0] <= intervals[scur - 1][1]){
            mx = max(intervals[scur][1] , mx);
            scur--;
        }
        if(scur != cur){
            intervals[scur][0] = min(intervals[scur][0] , intervals[cur][0]);
            intervals[scur][1] = max(intervals[scur][1] , mx);
            intervals.erase(intervals.begin() + scur + 1 , intervals.begin() + cur + 1);

        }
        return intervals;
    }
};
