// Leetcode 344

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Initialize two pointers: 'st' at the beginning and 'end' at the last index
        int st = 0;
        int end = s.size() - 1;

        // Continue swapping characters until the two pointers meet or cross
        while (st < end) {
            // Swap the characters at positions 'st' and 'end'
            swap(s[st], s[end]);

            // Move the 'st' pointer forward
            st++;

            // Move the 'end' pointer backward
            end--;
        }
    }
};
