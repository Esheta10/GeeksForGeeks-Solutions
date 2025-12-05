// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        int  n = arr.size();
        
        sort(arr.begin(),arr.end());
        int product1 = INT_MIN;
        int product2 = INT_MIN;
        
     
        product1 = arr[n-1]*arr[n-2]*arr[n-3];
        product2 = arr[0]*arr[1]*arr[n-1];
        
        return max(product1,product2);
    }
};