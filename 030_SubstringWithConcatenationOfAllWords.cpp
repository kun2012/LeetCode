/****************************************************************
You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).
****************************************************************/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size();
        int m = words.size();
        if (n == 0 || m == 0) return res;
        int len = words[0].size();
        unordered_map<string, int> um;
        for (int i = 0; i < m; i++) {
            um[words[i]]++;
        }
        for (int i = 0; i < len; i++) { //offset
            unordered_map<string, int> cm;
            int cnt = 0;
            int start_pos = i;
            
            for (int j = i; j < n; j += len) {
                if (j + len > n) break;
                string str = s.substr(j, len);
                if (um.find(str) == um.end()) {
                    cm.clear();
                    cnt = 0;
                    start_pos = j + len;
                    continue;
                }
                cm[str]++;
                cnt++;
                if (cm[str] > um[str]) {
                    while(true) {
                        string ts = s.substr(start_pos, len);
                        start_pos += len;
                        cnt--;
                        cm[ts]--;
                        if (ts == str) break;
                    }
                }
                if (cnt == m) {
                    res.push_back(start_pos);
                    cm[s.substr(start_pos, len)]--;
                    start_pos += len;
                    cnt--;
                }
            }
        }
        return res;
    }
};