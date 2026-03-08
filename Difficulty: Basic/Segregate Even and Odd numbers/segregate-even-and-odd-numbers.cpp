class Solution {
  public:
    void segregateEvenOdd(vector<int>& arr) {
        // code here
        
        auto mid = stable_partition(arr.begin(), arr.end(),[](int x){
            return x % 2 == 0;
        });
        
        sort(arr.begin(), mid);
        sort(mid, arr.end());
    }
};