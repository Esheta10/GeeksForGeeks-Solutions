class Solution {
  public:
    int n;
    int t[1001][1002];  // ✅ 1002 for p+1 indexing
    
    int solve(vector<vector<int>>& arr, int i, int p){
        
        if(i >= n)
            return 0;
        
        // ✅ Memoization check PEHLE karo
        if(t[i][p+1] != -1)
            return t[i][p+1];
        
        int take = 0;
        if(p == -1 || arr[i][0] > arr[p][1])  // ✅ arr[i][0]
            take = 1 + solve(arr, i+1, i);
        
        int skip = solve(arr, i+1, p);
        
        // ✅ Direct store and return
        return t[i][p+1] = max(take, skip);
    }
    
    int maxChainLen(vector<vector<int>> &arr) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        sort(arr.begin(), arr.end());
        return solve(arr, 0, -1);
    }
};