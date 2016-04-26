/****************************************************************
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.
For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
****************************************************************/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0, start = 0;
        while(true) {
            int cnt = 0;
            start = i;
            while(i < n && cnt + (i != start) + words[i].size() <= maxWidth) {
                if (i != start) cnt++;
                cnt += words[i].size();
                i++;
            }
            string s;
            if (i == n) {
                s += words[start];
                for (int j = start + 1; j < n; j++) {
                    s = s + " " + words[j];
                }
                for (int j = cnt; j < maxWidth; j++)
                    s += " ";
                res.push_back(s);
                break;
            }
            int num = i - start - 1;
            int extra = maxWidth - cnt;
            s += words[start];
            if (num == 0) {
                for (int j = 0; j < extra; j++)
                    s += " ";
                res.push_back(s);
                continue;
            }
            int t1 = extra / num;
            int t2 = extra % num;
            for (int j = start + 1; j < i; j++) {
                for (int k = 0; k <= t1; k++) {
                    s += " ";
                }
                if (t2 > 0) {
                    s += " ";
                    t2--;
                }
                s += words[j];
            }
            res.push_back(s);
        }
        return res;
    }
};