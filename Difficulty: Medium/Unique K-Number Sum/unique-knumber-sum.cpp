class Solution {
  public:
    void backtrack(int n, int k, vector<int>& temp, vector<vector<int>>& result, int idx){
        
        
        if(temp.size() == k && n==0){
            result.push_back(temp);
            return;
        }
        
        if(temp.size() == k || n <= 0)
            return;
            
        for(int i=idx; i<=9; i++){
            
            temp.push_back(i);  // choose
            backtrack(n-i, k, temp, result, i+1);   // recurse
            temp.pop_back();    // un-choose
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<int> temp; 
        vector<vector<int>> result;
        
        backtrack(n, k, temp, result, 1);
        
        return result;
    }
};