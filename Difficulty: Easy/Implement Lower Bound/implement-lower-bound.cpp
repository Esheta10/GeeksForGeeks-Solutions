class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        int left = 0;
        int right = n-1;
        int ans = n; // default value, if no element >= x
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(arr[mid] >= target){
                ans = mid; // potential answer, but search further left for even better ans
                right = mid - 1;
            } else {
                left = mid + 1; // search in the right half
            }
        }
        return ans;
    }
};
