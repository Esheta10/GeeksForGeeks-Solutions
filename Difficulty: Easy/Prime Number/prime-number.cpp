class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n == 1)
            return false; // 1 is not prime
            
        if(n==2 || n==3)
            return true; // 2 and 3 are prime
            
        if(n%2 == 0 || n%3 == 0)
            return false;
            
        for(int i=5; i*i<=n; i++){
            
            if(n%i == 0)
                return false;
        }
        return true;
    }
};
