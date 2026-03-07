class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int left = 0, right = n-1;
        
        vector<int> result(n);
        
        // even index -> max
        // odd index -> min
        for(int i=0; i<n; i++){
            
            if(i % 2 == 0)
                result[i] = arr[right--];
            else 
               result[i] = arr[left++];
            
        }
        
        for(int i=0; i<n; i++){
            
            arr[i] = result[i];
        }
        
    }
};