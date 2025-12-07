class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if(n==0)
            return 0;
            
        sort(arr.begin(), arr.end());
        int result = arr[n-1] - arr[0];
        
            
        for(int i=0; i<n-1; i++){
            
            int high = arr[i] + k;
            int low = arr[i+1] - k;
            
            if(low < 0)
                continue;
            
            int minHeight = min(arr[0]+k, low);
            int maxHeight = max(high, arr[n-1] - k);
            
            result = min(result,maxHeight - minHeight);
            
        }
        return result;
    }
};