// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int totalSum = 0;
        
        // Calculate total Sum
        for(int num : arr){
            
            totalSum += num;
        }
        
        // If totalSum is not divisble by 3 , impossible 
        if(totalSum % 3 != 0){
            return {-1,-1};
        }
        
        int targetSum = totalSum / 3;
        int currentSum = 0;
        int i=-1, j=-1;
        
        // Find first split point (i)
        for(int k=0; k<n-2; k++){
            currentSum += arr[k];
            if(currentSum == targetSum){
                i = k;
                break;
            }
        }
        // If first split not found
        if(i==-1)
            return {-1,-1};
        
        // Find second split point (j)
        currentSum = 0;
        for(int k = i+1; k<n-1; k++){
            currentSum += arr[k];
            if(currentSum == targetSum){
                j = k;
                break;
            }
        }
        
        if(j == -1)
            return {-1,-1};
            
        return {i,j};
    }
};