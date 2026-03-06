class Solution {
  public:
    vector<int> getSmaller(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        vector<int> result;
        
        for(int i=0; i<n; i++){
            
            if(arr[i] < target)
                result.push_back(arr[i]);
        }
        return result;
    }
};
