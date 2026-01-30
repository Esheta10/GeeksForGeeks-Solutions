class Solution {
  public:
    bool canSplit(vector<int>& arr, int k, int maxSum){
        
        int subarrayNeeded = 1;
        int currentSum = 0;
        
        for(int i=0; i<arr.size(); i++){
            
            if(currentSum + arr[i] <= maxSum){
                currentSum += arr[i];
            } else {
                subarrayNeeded++;
                currentSum = arr[i];
                
                if(subarrayNeeded > k)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int left = *max_element(arr.begin(), arr.end());
        int right = 0;
        
        for(int num: arr){
            right += num;
        }
        int result = right;
        
        while(left <= right){
            
            int mid = left + (right - left)/2;
            
            if(canSplit(arr, k, mid)){
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};