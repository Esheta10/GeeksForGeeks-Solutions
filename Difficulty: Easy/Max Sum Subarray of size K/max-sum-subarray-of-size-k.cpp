class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int windowSum = 0;
        int maxSum = INT_MIN;
        
        for(int i=0; i<k; i++){
            
            windowSum += arr[i];
        }
        
        maxSum = windowSum;
        
        for(int i=k; i<n; i++){
            
            windowSum += arr[i];
            windowSum -= arr[i-k];
            
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
};