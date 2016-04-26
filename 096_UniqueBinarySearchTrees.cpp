/****************************************************************
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
****************************************************************/
class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;
        for (int i = n + n; i >= n + 1; i--) {
            if (i & 1) {
                ans *= (long long)i;
            } else {
                ans *= 2;
            }
        }
        ans /= (n + 1);
        for (int i = n / 2; i >= 1; i --) {
            ans /= (long long)i;
        }
        return ans;
    }
};