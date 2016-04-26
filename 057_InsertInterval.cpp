/****************************************************************
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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

    int bsearch(int lo, int hi, vector<Interval>& intervals, int x, bool is_left) {
        if (lo == hi) {
            if (is_left) {
                if (x <= intervals[lo].end) return lo;
                return lo + 1;
            } else {
                if (x >= intervals[lo].start) return lo;
                return lo - 1;
            }
        }
        if (lo + 1 == hi) {
            if (is_left) {
                if (x <= intervals[lo].end) return lo;
                if (x <= intervals[hi].end) return hi;
                return hi + 1;
            } else {
                if (x >= intervals[hi].start) return hi;
                if (x >= intervals[lo].start) return lo;
                return lo - 1;
            }
        }
        int mid = (lo + hi) / 2;
        if (x < intervals[mid].start) return bsearch(lo, mid - 1, intervals, x, is_left);
        return bsearch(mid, hi, intervals, x, is_left);
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        if (n == 0) {
            res.push_back(newInterval);
            return res;
        }
        int lo =  newInterval.start, hi =  newInterval.end;
        int i = bsearch(0, n - 1, intervals, lo, 1);
        int j = bsearch(0, n - 1, intervals, hi, 0);
        if (i >= n) {
            res.insert(res.end(), intervals.begin(), intervals.end());
            res.push_back(newInterval);
            return res;
        }
        if (j < 0) {
            res.push_back(newInterval);
            res.insert(res.end(), intervals.begin(), intervals.end());
            return res;
        }
        if (i > j) {
            res.insert(res.end(), intervals.begin(), intervals.begin() + j + 1);
            res.push_back(newInterval);
            res.insert(res.end(), intervals.begin() + j + 1, intervals.end());
            return res;
        }
        res.insert(res.end(), intervals.begin(), intervals.begin() + i);
        res.push_back(Interval(min(lo, intervals[i].start), max(hi, intervals[j].end)));
        if (j < n - 1) {
            res.insert(res.end(), intervals.begin() + j + 1, intervals.end());
        }
        return res;
    }
};