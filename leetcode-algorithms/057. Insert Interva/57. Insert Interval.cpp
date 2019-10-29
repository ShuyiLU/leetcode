/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        bool ist=false;
        for (Interval itv: intervals) {
            if (itv.start>newInterval.end) {
                if (!ist) {
                    ans.push_back(newInterval); ist=true;
                }
                ans.push_back(itv);
            }
            else if (itv.end<newInterval.start) ans.push_back(itv);
            else newInterval=Interval(min(newInterval.start, itv.start), max(newInterval.end, itv.end));
        }
        if (!ist) ans.push_back(newInterval);
        return ans;
    }
};
