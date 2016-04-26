/****************************************************************
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
****************************************************************/
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
    bool static cmp(const Interval &p, const Interval &q) {
        if (p.start < q.start) return true;
        if (p.start > q.start) return false;
        return p.end < q.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> res;
        if (n == 0) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        int lo = intervals[0].start, hi = intervals[0].end;
        for (int i = 1; i < n; i++) {
            if (intervals[i].start > hi) {
                res.push_back(Interval(lo, hi));
                lo = intervals[i].start;
                hi = intervals[i].end;
            } else {
                hi = max(intervals[i].end, hi);
            }
        }
        res.push_back(Interval(lo, hi));
        return res;
    }
};