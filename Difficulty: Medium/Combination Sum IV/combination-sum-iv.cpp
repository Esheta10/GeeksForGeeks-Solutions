class Solution {
  public:
    int n;
    int t[201][1001];
    int backtrack(int idx, vector<int>& arr, int key){
        
        if(key == 0)
            return 1;
        
        if(idx >= n || key<0)
            return 0;
            
        if(t[idx][key] != -1)
            return t[idx][key];
            
        int take_idx = backtrack(0, arr, key - arr[idx]);
        int reject_idx = backtrack(idx+1, arr, key);
        
        return t[idx][key] = take_idx + reject_idx;
    }
    int combinationSum4(vector<int>& arr, int key) {
        // complete the function here
        n = arr.size();
        memset(t, -1, sizeof(t));
        return backtrack(0, arr, key);
    }
};