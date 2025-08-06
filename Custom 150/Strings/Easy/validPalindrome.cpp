// Leetcode 125

class Solution {
public:
    // Helper function to check if a character is alphanumeric
    bool isAlphaNum(char ch) {
        // Return true if the character is a digit or a letter (case insensitive)
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }

    // Function to check if the given string is a palindrome (ignoring non-alphanumeric and case)
    bool isPalindrome(string s) {
        int st = 0;                       // Start pointer
        int end = s.length() - 1;        // End pointer

        // Loop until the two pointers meet
        while (st < end) {
            // Skip non-alphanumeric characters from the start
            if (!isAlphaNum(s[st])) {
                st++;
                continue;
            }

            // Skip non-alphanumeric characters from the end
            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[st]) != tolower(s[end])) {
                return false; // Not a palindrome if mismatch found
            }

            // Move both pointers toward the center
            st++;
            end--;
        }

        // All characters matched, so it's a palindrome
        return true;
    }
};
