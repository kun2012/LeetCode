/****************************************************************
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
****************************************************************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            c += digits[i];
            if (c >= 10) {
                digits[i] = c - 10;
                c = 1;
            }else {
                digits[i] = c;
                c = 0;
            }
        }
        if (c > 0) {
            digits.insert(digits.begin(), c);
        }
        return digits;
    }
};