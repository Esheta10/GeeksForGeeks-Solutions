class Solution {
  public:
    int Sum(vector<int> &arr){
        
        int sum = 0;
        for(int &num : arr){
            sum += num;
        }
        return sum;
    }
    void backtrack(vector<int>& arr, int target, vector<int>& temp, vector<vector<int>>& result, int idx){
        
        if(idx >= arr.size() || Sum(temp) > target)
            return;
            
        if(Sum(temp) == target){
            result.push_back(temp);
            return;
        }
        
        temp.push_back(arr[idx]);
        backtrack(arr, target, temp, result, idx);
        
        temp.pop_back();
        backtrack(arr, target, temp, result, idx+1);
    }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<int> temp;
        
        vector<vector<int>> result;
        
        backtrack(arr, target, temp, result, 0);
        
        return result;
    }
};