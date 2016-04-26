/****************************************************************
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
****************************************************************/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        //bfs
        unordered_map<string, int> um;
        queue<string> que;
        que.push(beginWord);
        um[beginWord] = 1;
        while(!que.empty()) {
            string s = que.front();
            int len = um[s];
            que.pop();
            for (int i = 0; i < s.size(); i++) {
                char t = s[i];
                for (int j = 'a'; j <= 'z'; j++) {
                    s[i] = j;
                    if (s == endWord) return len + 1;
                    if (wordList.find(s) != wordList.end()) {
                        que.push(s);
                        um[s] = len + 1;
                        wordList.erase(s);
                    }
                }
                s[i] = t;
            }
        }
        return 0;
    }
};