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
    bool static compare(const Interval& a, const Interval& b) {
        // if(a.start == b.start) {
        //     return a.end > b.end;
        // }
        return a.start < b.start;

    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 1; i<intervals.size(); ++i) {
            // cout<<interval.start<<" "<<interval.end<<"\n";
            if(intervals[i-1].end > intervals[i].start)
                return false;
        }
        return true;
    }
};
