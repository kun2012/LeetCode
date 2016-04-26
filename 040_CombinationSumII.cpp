/****************************************************************
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
****************************************************************/
class Solution {
public:
    vector<vector<int> > res;
    void dfs(int p, int st, vector<int> &cur, vector<int> &a, unordered_set<int> &ss) {
        if (p == 0) {
            res.push_back(cur);
            return ;
        }
        for (int i = st; i < a.size(); i++) {
            if (cur.size() == 0) {
                if (ss.find(a[i]) != ss.end()) continue;
                ss.insert(a[i]);
            }
            if (p >= a[i]) {
                cur.push_back(a[i]);
                dfs(p - a[i], i + 1, cur, a, ss);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        unordered_set<int> ss;
        vector<int> cur;
        dfs(target, 0, cur, candidates, ss);
        return res;
    }
};