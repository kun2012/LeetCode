/****************************************************************
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
****************************************************************/
class Solution {
public:

    int bleftsearch(int lo, int hi, vector<int> &nums, int x) {
        if (lo > hi) return -1;
        if (lo == hi) {
            if (x == nums[lo]) return lo;
            return -1;
        }
        if (lo + 1 == hi) {
            if (x == nums[lo]) return lo;
            if (x == nums[hi]) return hi;
            return -1;
        }
        int mid = (lo + hi) / 2;
        if (nums[mid] >= x) return bleftsearch(lo, mid, nums, x);
        return bleftsearch(mid + 1, hi, nums, x);
    }
    
    int brightsearch(int lo, int hi, vector<int> &nums, int x) {
        if (lo > hi) return -1;
        if (lo == hi) {
            if (x == nums[lo]) return lo;
            return -1;
        }
        if (lo + 1 == hi) {
            if (x == nums[hi]) return hi;
            if (x == nums[lo]) return lo;
            return -1;
        }
        int mid = (lo + hi) / 2;
        if (nums[mid] > x) return brightsearch(lo, mid - 1, nums, x);
        return brightsearch(mid, hi, nums, x);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int x = bleftsearch(0, nums.size() - 1, nums, target);
        if (x == -1) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(x);
        int y = brightsearch(x, nums.size() - 1, nums, target);
        res.push_back(y);
        return res;
    }
};