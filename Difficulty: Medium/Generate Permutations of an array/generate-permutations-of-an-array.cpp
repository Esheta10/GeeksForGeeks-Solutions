class Solution {
  public:
    int n;
    vector<vector<int>> result;
    unordered_set<int> st;
    void backtrack(vector<int>& temp, vector<int>& arr){
        
        if(temp.size() == n){
            result.push_back(temp);
            return;
        }
        
        for(int i=0; i<n; i++){
            
            if(st.find(arr[i]) == st.end()){
                
                temp.push_back(arr[i]);
                st.insert(arr[i]);
                backtrack(temp, arr);
                
                temp.pop_back();
                st.erase(arr[i]);
            }
            
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        n = arr.size();
        
        vector<int> temp;
        
        backtrack(temp, arr);
        
        return result;
    }
};