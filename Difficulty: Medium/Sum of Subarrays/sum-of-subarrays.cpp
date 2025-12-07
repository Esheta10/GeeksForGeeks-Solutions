class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        
        // Brute Force - O(n^2)
        // int totalSum = 0;
        // int n = arr.size();
        
        // for(int i=0;i<n;i++){
            
        //     int currentSum = 0;
        //     for(int j=i; j<n; j++){
                
        //         currentSum += arr[j];
        //         totalSum += currentSum;
        //     }
        // }
        // return totalSum;
        
        // Optimized Solution - O(n)
        int n = arr.size();
        int totalSum = 0;
        
        for(int i=0;i<n;i++){
            
            int count = (i+1)*(n-i);
            int contribution = arr[i] * count;
            
            totalSum += contribution;
        }
        return totalSum;
    }
};