/****************************************************************
Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
****************************************************************/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        int i = 0;
        while(i < n) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            if (path[i] == '.' && i + 1 == n) {
                i++;
                continue;
            }
            if (path[i] == '.' && path[i + 1] == '/') {
                i += 2;
                continue;
            }
            if (i + 2 == n && path[i] == '.' && path[i + 1] == '.') {
                i += 2;
                if (!st.empty()) st.pop();
                continue;
            }
            if (i + 2 < n && path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/') {
                i += 3;
                if (!st.empty()) st.pop();
                continue;
            }
            string s = "";
            while(i < path.size() && path[i] != '/') {
                s += path[i];
                i++;
            }
            st.push(s);
        }
        if (st.empty()) {
            return "/";
        }
        string ans;
        while(!st.empty()) {
            ans = st.top() + "/" + ans;
            st.pop();
        }
        ans = "/" + ans.substr(0, ans.size() - 1);
        return ans;
    }
};