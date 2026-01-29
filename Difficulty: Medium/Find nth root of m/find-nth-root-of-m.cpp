class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int l = 1;
        int r = m;
        
        if(m==0)
            return 0;
            
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            int power = 1;
            for(int i=0; i<n; i++){
                
                power = power * mid;
                
                if(power > m)
                    break;
            }
            
            if(power == m)
                return mid;
            else if (power < m)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};