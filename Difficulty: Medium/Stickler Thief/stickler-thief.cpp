class Solution {
  public:
    int t[100001];
    int solve(vector<int>& arr, int i, int n){
        
        if(i>=n)
            return 0;
            
        if(t[i] != -1)
            return t[i];
            
        int steal = arr[i] + solve(arr, i+2, n);
        int skip = solve(arr, i+1, n);
        
        return t[i] = max(steal,skip);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(arr,0,n);
    }
};