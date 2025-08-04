//gfg = https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        vector <int> ans;
        int maximum = INT_MIN;
        int n= arr.size();
        
        for(int i=n-1; i>=0; i--) {
            if(arr[i] >= maximum){
                ans.push_back(arr[i]);
            }
            
            maximum = max(maximum, arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
