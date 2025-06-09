// User function Template for C++

class Solution {
  public:
    vector<vector<int>> result;
    void solve(vector<int>& arr, int i, vector<int>& temp)
    {
        if(i>=arr.size())
        {
           result.push_back(temp);
           return;
        }
        temp.push_back(arr[i]);
        solve(arr,i+1,temp);
        temp.pop_back();
        solve(arr,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int> temp;
        sort(arr.begin(),arr.end());
        solve(arr,0,temp);
        sort(result.begin(), result.end());
        return result;
    }
};