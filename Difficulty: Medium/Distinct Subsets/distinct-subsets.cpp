class Solution {
  public:
    int n;
    vector<vector<int>> result;
    void backtrack(int idx, vector<int>& temp, vector<int>& arr){
        
       result.push_back(temp);
       
       unordered_set<int> st;
       
       for(int i=idx; i<n; i++){
           
           if(st.find(arr[i]) != st.end()) continue;
           
           temp.push_back(arr[i]);
           st.insert(arr[i]);
           
           backtrack(i+1, temp, arr);
           
           temp.pop_back();
       }
    }
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<int> temp;
        backtrack(0, temp, arr);
        
        return result;
    }
};