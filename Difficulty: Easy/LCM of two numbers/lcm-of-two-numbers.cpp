class Solution {
  public:
    int gcd(int a, int b){
        
        if(b==0)
            return a;
        else
            return gcd(b, a%b);
    }
    int lcm(int a, int b) {
        // code here
        return ((a*b)/ gcd(a,b));
    }
};