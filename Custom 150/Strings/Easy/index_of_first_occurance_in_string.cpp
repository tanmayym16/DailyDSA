//Leetcode 28

class Solution {
public:
    int strStr(string haystack, string needle) {
        // Length of haystack (main string)
        int n = haystack.length();

        // Length of needle (substring to search)
        int m = needle.length();

        // Edge case: if needle is empty, return 0 as per the problem statement
        if (m == 0) return 0;

        // Loop through haystack from index 0 to (n - m)
        // because we need at least 'm' characters remaining to match the needle
        for (int i = 0; i <= n - m; i++) {
            // Extract a substring of length 'm' starting from index 'i'
            // and compare it with needle
            if (haystack.substr(i, m) == needle) {
                // If a match is found, return the starting index
                return i;
            }
        }

        // If no match is found after scanning, return -1
        return -1;
    }
};
