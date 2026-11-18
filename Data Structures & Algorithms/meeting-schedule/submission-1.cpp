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

        std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });


        int prevEnd = -1;

        for (auto interval : intervals) {
            if (prevEnd != -1) {
                
                // check if we have invalid interval
                if (prevEnd > interval.start) {
                    return false;
                }
            }
            prevEnd = interval.end;
        }
        return true;
    }
};

/*
Itterate through vector of intervals
track start and end time

*/
