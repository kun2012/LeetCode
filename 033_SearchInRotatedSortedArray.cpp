/****************************************************************
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
****************************************************************/
class Solution {
public:
    int binsearch(vector<int> &nums, int lo, int hi, int target) {
        if (lo == hi) {
            if (nums[lo] == target) return lo;
            else return -1;
        }
        if (lo + 1 == hi) {
            if (nums[lo] == target) return lo;
            if (nums[hi] == target) return hi;
            return -1;
        }
        int mid = (lo + hi) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] <= nums[hi]) {
            if (target > nums[mid] && target <= nums[hi]) {
                return binsearch(nums, mid + 1, hi, target);
            }else {
                return binsearch(nums, lo, mid - 1, target);
            }
        }
        if (nums[lo] <= nums[mid]) {
            if (target >= nums[lo] && target < nums[mid]) {
                return binsearch(nums, lo, mid - 1, target);
            } else {
                return binsearch(nums, mid + 1, hi, target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return binsearch(nums, 0, nums.size() - 1, target);
    }
};