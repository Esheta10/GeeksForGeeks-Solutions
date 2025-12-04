// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int minSum = a[0];
        int currentSum = a[0];
        
        int n = a.size();
        
        for(int i=1;i<n;i++)
        {
            
            currentSum = min(a[i], currentSum + a[i]);
            minSum = min(minSum, currentSum);
        }
        return minSum;
    }
};
