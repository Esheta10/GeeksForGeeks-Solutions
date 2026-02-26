class Solution {
  public:
    int largestPrimeFactor(int n) {
        // code here
        int maxFactor = -1;
        
        for(int i=2; i<=n; i++){
            
            while(n%i==0 && n>0){
                maxFactor = i;
                n = n/i;
            }
        }
        return maxFactor;
    }
};