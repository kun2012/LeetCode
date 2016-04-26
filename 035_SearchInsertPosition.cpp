/****************************************************************
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
****************************************************************/
class Solution {
public:
    int bsearch(int lo, int hi, vector<int> &nums, int x) {
        if (lo == hi) {
            if (nums[lo] == x) return lo;
            if (x < nums[lo]) return lo;
            return lo + 1;
        }
        if (lo + 1 == hi) {
            if (nums[hi] == x) return hi;
            if (nums[lo] == x) return lo;
            if (x > nums[hi]) return hi + 1;
            if (x > nums[lo]) return hi;
            return lo;
        }
        int mid = (lo + hi) / 2;
        if (nums[mid] == x) return mid;
        if (nums[mid] < x) return bsearch(mid + 1, hi, nums, x);
        return bsearch(lo, mid - 1, nums, x);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        return bsearch(0, nums.size() - 1, nums, target);
    }
};