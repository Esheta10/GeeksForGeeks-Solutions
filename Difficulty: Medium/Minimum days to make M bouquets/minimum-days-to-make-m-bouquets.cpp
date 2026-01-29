class Solution {
  public:
    long long countBouquets(vector<int>& arr, int day, int k){
        int bouquets = 0;
        int consecutive = 0;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i] <= day){
                consecutive++;
                if(consecutive==k){
                    bouquets++;
                    consecutive=0;
                }
            } else {
                consecutive = 0;
            }
        }
        return bouquets;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        
        long long totalRosesNeeded = (long long)m*k;
        if(totalRosesNeeded > n)
            return -1; // impossible to create m bouquet with n roses
            
        int minDay = INT_MAX;
        int maxDay = INT_MIN;
        for(int i=0;i<n;i++){
            
            minDay = min(minDay, arr[i]);
            maxDay = max(maxDay, arr[i]);
        }
        
        int left = minDay;
        int right = maxDay;
        int result = -1;
        
        while(left <= right){
            int mid = left +  (right-left)/2;
            
            long long bouquetCount = countBouquets(arr, mid, k);
            
            if(bouquetCount >= m){
                result = mid; //potential answer
                right = mid-1;  // search further left for an even smaller value
            } else{
                left = mid + 1; // not enough bouquets, move right
            }
        }
        return result;
    }
};