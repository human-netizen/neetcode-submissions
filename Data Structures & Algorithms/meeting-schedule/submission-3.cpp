/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin() , intervals.end() , 
        [](Interval one , Interval two){
            if(one.start == two.start)return one.end < two.end;
            return one.start < two.start;
        });
        for(int i = 1 ; i < intervals.size() ; i++){
            if(intervals[i].start < intervals[i - 1].end)return 0;
        }
        return 1;
    }
};
