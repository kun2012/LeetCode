/****************************************************************
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
****************************************************************/
class Solution { //bfs + dfs
public:
    vector<vector<string>> res;
    void generate_word_level(string start, string end, unordered_set<string> &words, unordered_map<string, unordered_set<string> > &um) {
        unordered_set<string> oldl, curl, newl;
        curl.insert(start);
        bool reach_end = false;
        while(!curl.empty()) {
            for (auto it = curl.begin(); it != curl.end(); ++it) {
                for (int i = 0; i < it->size(); i++) {
                    string s = *it;
                    for (int j = 'a'; j <= 'z'; j++) {
                        s[i] = j;
                        if (s == end) {
                            um[*it].insert(s);
                            reach_end = true;
                            continue;
                        }
                        if (!words.count(s) || curl.count(s) || oldl.count(s)) continue;
                        um[*it].insert(s);
                        newl.insert(s);
                    }
                }
            }
            if (reach_end) break;
            oldl = curl;
            curl = newl;
            newl.clear();
        }
        if (!reach_end) um.clear();
    }
    
    void generate_path(string cw, string end, vector<string> &cur, unordered_map<string, unordered_set<string> > &um) {
        if (cw == end) {
            res.push_back(cur);
            return ;
        }
        if (!um.count(cw)) {
            return ;
        }
        unordered_set<string> us = um[cw];
        for (auto it = us.begin(); it != us.end(); it++) {
            cur.push_back(*it);
            generate_path(*it, end, cur, um);
            cur.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, unordered_set<string> > um;
        generate_word_level(beginWord, endWord, wordList, um);
        if (um.empty()) return res;
        vector<string> cur;
        cur.push_back(beginWord);
        generate_path(beginWord, endWord, cur, um);
        return res;
    }
};