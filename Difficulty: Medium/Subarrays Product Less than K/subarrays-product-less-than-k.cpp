

class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n,
                                            long long k) {
                                                
            long long count = 0;
            long long product = 1;
            int left = 0;
            
            if(k<=1)
                return 0;
            
            for(int right = 0; right<n; right++){
                
                product *= arr[right];
                
                while(product >= k){
                    product /= arr[left];
                    left++;
                }
                count += right - left + 1;
            }
            return count;                                        
    }
};