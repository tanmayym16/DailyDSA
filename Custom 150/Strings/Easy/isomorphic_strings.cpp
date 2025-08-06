//Leetcode 205

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If the lengths of the strings differ, they can't be isomorphic
        if (s.length() != t.length()) return false;

        // Two hash maps to store the last seen positions of each character
        unordered_map<char, int> map_s; // For characters in string s
        unordered_map<char, int> map_t; // For characters in string t

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i]; // Character from string s at index i
            char c2 = t[i]; // Character from string t at index i

            // Check if the last seen positions of c1 and c2 match
            // If not, the mapping is inconsistent → not isomorphic
            if (map_s[c1] != map_t[c2]) return false;

            // Store the current index + 1 as the last seen position
            // Why i + 1? Because default value for int in an unordered_map is 0
            // So we use i + 1 to distinguish between "not seen yet" (0) and "seen at index 0"
            map_s[c1] = i + 1;
            map_t[c2] = i + 1;
        }

        // If all characters map consistently, the strings are isomorphic
        return true;
    }
};
