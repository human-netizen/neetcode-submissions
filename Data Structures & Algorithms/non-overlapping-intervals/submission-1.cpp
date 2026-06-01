class Solution {
public:
    static int cmp(vector<int>&a , vector<int>&b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , cmp);
        int lastOne = -1;
        int cnt = 0;
        for(int i = 0 ; i < intervals.size() ; i++){
            cout << intervals[i][0] << " " << intervals[i][1] << endl;
            if(intervals[i][0] >= lastOne){
                lastOne = intervals[i][1];
                cnt++;
            }
        }
        return intervals.size() - cnt;
    }
};
