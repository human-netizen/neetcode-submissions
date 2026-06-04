/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin() , intervals.end() , 
        [](Interval& one , Interval& two){
            if(one.end == two.end)return one.start < two.start;
            return one.end < two.start;
        });
        set<int>st;
        st.insert(intervals[0].end);
        for(int i = 1 ; i < intervals.size() ; i++){
            auto it = st.upper_bound(intervals[i].start);
            if(it != st.begin()){
                it--;
                st.erase(it);
            }
            st.insert(intervals.end);
        }
        return st.size() ;
    }
};
