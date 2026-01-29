class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        if(n==0 || n==1)
            return n;
            
        int l=1;
        int r=n;
        int result = 0;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(mid == n/mid) // mid * mid == n --> Integer overflow se bachne ke liye 
                return mid;
            else if(mid < n/mid){   // mid * mid < n
                result = mid;   // potential answer
                 l = mid+1;
            }
            else{   // mid * mid > n
                r = mid-1;
            }
        }
        return result;
    }
};