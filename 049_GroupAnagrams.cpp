/****************************************************************
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
****************************************************************/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> um;
        vector<vector<string>> res;
        int cnt = 0;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (um.find(s) == um.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                res.push_back(v);
                um[s] = cnt++;
            } else {
                res[um[s]].push_back(strs[i]);
            }
        }
        for (int i = 0; i < cnt; i++) {
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};