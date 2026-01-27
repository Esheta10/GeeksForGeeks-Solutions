// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int ceil = -1;
        int left = 0;
        int right = n - 1;
    
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
           if (arr[mid] >= x) {
                ceil = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    
        return ceil;
    }
};