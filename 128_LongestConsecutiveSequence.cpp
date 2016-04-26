/****************************************************************
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
****************************************************************/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            se.insert(nums[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (se.find(nums[i]) == se.end()) continue;
            int cnt = 1;
            int le = nums[i] - 1, ri = nums[i] + 1;
            while(se.find(le) != se.end()) {
                se.erase(le);
                le--;
                cnt++;
            }
            while(se.find(ri) != se.end()) {
                se.erase(ri);
                ri++;
                cnt++;
            }
            if (cnt > res) res = cnt;
        }
        return res;
    }
};