/****************************************************************
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].
****************************************************************/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> p;
        vector<int> q;
        p.push_back(1);
        for (int i = 2; i <= rowIndex; i++) {
            q.push_back(1);
            for (int j = 2; j < i; j++) {
                q.push_back(p[j - 2] + p[j - 1]);
            }
            q.push_back(1);
            swap(p, q);
            q.clear();
        }
        return p;
    }
};