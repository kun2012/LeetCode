/****************************************************************
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
****************************************************************/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        for (int i = 0; i + needle.size() - 1 < haystack.size(); i++) {
            bool isfind = true;
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    isfind = false;
                    break;
                }
            }
            if (isfind) return i;
        }
        return -1;
    }
};