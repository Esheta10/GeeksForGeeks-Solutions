//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        multiset<int> s;
        vector<int> result(n);
        
        for(int i=n-1;i>=0;i--){
            
            auto it = s.upper_bound(arr[i]);
            
            if(it != s.end()){
                result[i] = *it;
            } else {
                result[i] = -1;
            }
            s.insert(arr[i]);
        }
        return result;
    }
};