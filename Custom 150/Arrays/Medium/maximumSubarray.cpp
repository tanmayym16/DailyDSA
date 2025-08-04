//Leetcode 53
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maximum= INT_MIN;
        int n= nums.size();

        for(int i=0; i<n; i++){
            sum+= nums[i];
            if(sum > maximum){
                maximum = sum;
            }if(sum < 0){
                sum= 0;
            }
        }
        return maximum;
    }
};
