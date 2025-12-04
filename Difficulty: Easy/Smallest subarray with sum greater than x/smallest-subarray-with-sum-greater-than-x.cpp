class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        
        int i=0,j=0;
        int n = arr.size();
        int minL=INT_MAX;
        
        int sum=0;
        
        while(j<n){
            
            sum += arr[j];
            
            while(sum > x){
                
                minL = min(minL, j-i+1);
                
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return minL==INT_MAX ? 0 : minL;
    }
};