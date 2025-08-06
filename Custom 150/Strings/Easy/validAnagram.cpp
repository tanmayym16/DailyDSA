// Leetcode 242

class Solution {
public:
    // Function to check if two strings are anagrams of each other
    bool isAnagram(string s, string t) {
        // Step 1: Sort both strings
        // If s = "anagram", it becomes "aaagmnr"
        // If t = "nagaram", it also becomes "aaagmnr"
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Step 2: Compare the sorted strings
        // If they are equal, then t is an anagram of s
        return s == t;
    }
};
