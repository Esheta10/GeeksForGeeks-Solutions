
class Solution {
  public:
    int nthTribonacci(int n) {
        // code here
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        int a=0;
        int b=1;
        int c=1;
        int d=a+b+c;
        
        for(int i=3;i<=n;i++)
        {
            d=a+b+c;
            
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};
