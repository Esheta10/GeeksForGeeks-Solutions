
class Solution {
  public:
    void arrange(vector<long long>& arr) {
        //  code here
        long long n = arr.size();
        
        for(int i=0; i<n; i++){
            
            long long newVal = arr[arr[i]] % n;
            arr[i] += newVal * n;
        }
        
        for(int i=0; i<n; i++){
            
            arr[i] = arr[i] / n;
        }
    }
};