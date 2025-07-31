//link- https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n1= a.size();
        int n2= b.size();
        int i= 0;
        int j= 0;
        
        vector <int> unionArr;
        while(i<n1 && j<n2){
            if(a[i] <= b[j]){
                if(unionArr.empty() || unionArr.back() != a[i]){
                    unionArr.push_back(a[i]);
                }
                i++;
            } else {
                if(unionArr.empty() || unionArr.back() != b[j]){
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }   
        while(j < n2){
            if(unionArr.empty() || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }  
        while(i < n1){
                if(unionArr.empty() || unionArr.back() != a[i]){
                    unionArr.push_back(a[i]);
                }
                i++;
        }
        return unionArr;
    }
};
