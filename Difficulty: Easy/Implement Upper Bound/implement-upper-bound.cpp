class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int ans = n; // default value, if no element > x 
        
        while(left <= right){
            
            int mid = left + (right-left)/2;
            
            if(arr[mid] > target){
                ans = mid; // potential answer
                right = mid-1; // search further left
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
