class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
        // code here
        
        vector<vector<int>> res;
        
        if(arr.empty()){
        res.push_back({lower, upper});
        return res;
    }
            
        if(lower < arr[0])
            res.push_back({lower,arr[0]-1});
            
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1] - arr[i] > 1){
                res.push_back({arr[i] + 1, arr[i+1] - 1});
            }
        }
        
        if(upper > arr.back())
            res.push_back({arr.back()+1, upper});
            
            
        return res;
    }
};