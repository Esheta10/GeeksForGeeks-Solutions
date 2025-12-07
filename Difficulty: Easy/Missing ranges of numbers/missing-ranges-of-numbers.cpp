class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
        // code here
        vector<vector<int>> result;
        int next_val = lower;
        
        for(int num : arr){
            
            if(num > next_val)
                result.push_back({next_val, num-1});
                
            next_val = num+1;
            
        }
         if(next_val <= upper)
                result.push_back({next_val, upper});
                
        return result;
    }
};