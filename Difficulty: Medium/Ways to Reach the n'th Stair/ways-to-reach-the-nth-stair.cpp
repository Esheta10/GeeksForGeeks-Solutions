class Solution {
  public:
    int t[41];
    int solve(int n){
        
        if(n < 0)
            return 0;
        
        if(n == 0)
            return 1;
            
        if(t[n] != -1)
            return t[n];
            
        int one_step = solve(n-1);
        int two_steps = solve(n-2);
        
        return t[n] = one_step + two_steps;
    }
    int countWays(int n) {
        // your code here
        memset(t, -1, sizeof(t));
        
        return solve(n);
    }
};
