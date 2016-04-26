/****************************************************************
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
****************************************************************/
// stoi(c++11) : convert string to int

class Solution {
public:
    vector<string> res;
    bool is_valid(string &s) {
        int len = s.size();
        if (len < 1 || len > 3) return false;
        if (len > 1 && s[0] == '0') return false;
        if (stoi(s) > 255) return false;
        return true;
    }
    void dfs(int p, int dep, string &s, string cur) {
        if (dep == 4) {
            string str = s.substr(p);
            if (is_valid(str)) {
                res.push_back(cur + str);
            }
            return ;
        }
        for (int i = 1; i <= 3; i++) {
            if (p + i - 1>= s.size()) break;
            string tmp = s.substr(p, i);
            if (!is_valid(tmp)) continue;
            dfs(p + i, dep + 1, s, cur + tmp + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(0, 1, s, "");
        return res;
    }
};