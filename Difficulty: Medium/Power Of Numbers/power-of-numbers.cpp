class Solution {
  public:
    int getReverse(int n){
        
        int rev = 0;
        while(n > 0){
            
            int rem = n%10;
            rev = rev*10 + rem;
            n = n/10;
        }
        return rev;
    }
    int power(int n, int p){
        
        if(p==0)
            return 1;
            
        return n*power(n, p-1);
    }
    int reverseExponentiation(int n) {
        // code here
        
        // pehle reverse nikalo 
        int rev = getReverse(n);
        
        // now calculate power
        return power(n, rev); // n^rev
        
    }
};