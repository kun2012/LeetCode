/****************************************************************
The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
****************************************************************/
class Solution {
public:
    int f[10];
    void dfs(string &s, int n, int k, vector<int> &cur) {
        if (n == 0) {
            return ;
        }
        int x = k / f[n - 1];
        s += char(48 + cur[x]);
        cur.erase(cur.begin() + x);
        dfs(s, n - 1, k - x * f[n - 1], cur);
    }
    string getPermutation(int n, int k) {
        f[0] = 1;
        for (int i = 1; i <= 9; i++) {
            f[i] = f[i - 1] * i;
        }
        string s = "";
        vector<int> cur;
        for (int i = 1; i <= n; i++) {
            cur.push_back(i);
        }
        dfs(s, n, k - 1, cur);
        return s;
    }
};