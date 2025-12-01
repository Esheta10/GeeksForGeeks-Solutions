// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        int n1 = arr[n-1] * arr[n-2] * arr[n-3];
        int n2 = arr[n-1] * arr[0] * arr[1];
        
        return max(n1,n2);
    }
};