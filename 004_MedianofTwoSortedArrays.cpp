/****************************************************************
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
****************************************************************/
class Solution {
public:
    double find_kth(vector<int> &a, int x, int y, vector<int> &b, int p, int q, int k) {
       if (x > y) {
           return b[p + k - 1];
       }
       if (p > q) {
           return a[x + k - 1];
       }
       int ia = (x + y) / 2;
       int ib = (p + q) / 2;
       int la = ia - x + 1;
       int lb = ib - p + 1;
       if (la + lb > k) {
           if (a[ia] > b[ib]) {
               return find_kth(a, x, ia - 1, b, p, q, k);
           }else {
               return find_kth(a, x, y, b, p, ib - 1, k);
           }
       }
       //la + lb <= k
       if (a[ia] < b[ib]) {
           return find_kth(a, ia + 1, y, b, p, q, k - la);
       }else {
           return find_kth(a, x, y, b, ib + 1, q, k - lb);
       }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        if (n % 2 != 0) {
            return find_kth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, (n + 1)/2);
        }
        double t1 = find_kth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, n / 2);
        double t2 = find_kth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, n / 2 + 1);
        return ( t1 + t2 ) / 2.0;
    }
};