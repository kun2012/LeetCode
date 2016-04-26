/****************************************************************
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
****************************************************************/
class Solution {
public:
        bool binsearch(vector<int> &nums, int lo, int hi, int target) {
        if (lo == hi) {
            if (nums[lo] == target) return true;
            return false;
        }
        if (lo + 1 == hi) {
            if (nums[lo] == target) return true;
            if (nums[hi] == target) return true;
            return false;
        }
        int mid = (lo + hi) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < nums[hi]) {
            if (target > nums[mid] && target <= nums[hi]) {
                return binsearch(nums, mid + 1, hi, target);
            }else {
                return binsearch(nums, lo, mid - 1, target);
            }
        } else if (nums[lo] < nums[mid]) {
            if (target >= nums[lo] && target < nums[mid]) {
                return binsearch(nums, lo, mid - 1, target);
            } else {
                return binsearch(nums, mid + 1, hi, target);
            }
        } else if (nums[lo] == nums[mid]) {
            return binsearch(nums, lo + 1, hi, target);
        } else if (nums[mid] == nums[hi]) {
            return binsearch(nums, lo, hi - 1, target);
        }
    }
    bool search(vector<int>& nums, int target) {
        return binsearch(nums, 0, nums.size() - 1, target);
    }
};