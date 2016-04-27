/****************************************************************
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
****************************************************************/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0) return 0;
        if (points.size() == 1) return 1;
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            int cur = 1;
            unordered_map<double, int> um;
            int vcnt = 0;
            int cop = 0;
            for (int j = 0; j < points.size(); j++) {
                if (j == i) continue;
                double dx = points[i].x - points[j].x;
                double dy = points[i].y - points[j].y;
                if (dx == 0 && dy == 0) cop++;
                else if (dx == 0) {
                    if (vcnt == 0) vcnt = 2;
                    else vcnt++;
                    cur = max(cur, vcnt);
                } else {
                    double k = dy / dx;
                    if (um[k] == 0) um[k] = 2;
                    else um[k]++;
                    cur = max(cur, um[k]);
                }
            }
            ans = max(ans, cur + cop);
        }
        return ans;
    }
};