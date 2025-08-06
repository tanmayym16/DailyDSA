//Leetcode 14

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        // If the input vector is empty, return an empty string
        if(n == 0) return "";

        // Sort the strings lexicographically
        sort(strs.begin(), strs.end());

        // After sorting, the first and last strings will have the maximum difference
        string a = strs[0];        // First string in the sorted list
        string b = strs[n - 1];    // Last string in the sorted list
        string ans = "";           // To store the result

        // Compare characters one by one until they mismatch
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == b[i])
                ans += a[i];       // Append matching character to result
            else
                break;             // Stop at the first mismatch
        }

        // Return the longest common prefix
        return ans;
    }
};
//start of array is a and end of array is b
