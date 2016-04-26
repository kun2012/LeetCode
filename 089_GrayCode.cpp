/****************************************************************
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
****************************************************************/
class Solution {
public:
    void dfs(int p, int dep, int n, int is_flip, vector<int> &res) {
        if (dep > n) {
            res.push_back(p);
            return ;
        }
        if (is_flip) {
            dfs(p + p + 1, dep + 1, n, 1 - is_flip, res);
            dfs(p + p, dep + 1, n, is_flip, res);
        } else {
            dfs(p + p, dep + 1, n, is_flip, res);
            dfs(p + p + 1, dep + 1, n, 1 - is_flip, res);
        }
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        dfs(0, 1, n, 0, res);
        return res;
    }
};