/****************************************************************
Write a function to find the longest common prefix string amongst an array of strings.
****************************************************************/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if (strs.size() < 1) return s;
        for (int p = 0; ; p++) {
            if (p >= strs[0].size()) break;
            char c = strs[0][p];
            bool isend = false;
            for (int i = 1; i < strs.size(); i++) {
                if (p >= strs[i].size()) {
                    isend = true;
                    break;
                }
                if (c != strs[i][p]) {
                    isend = true;
                    break;
                }
            }
            if (isend) break;
            s += c;
        }
        return s;
    }
};