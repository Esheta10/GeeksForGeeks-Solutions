class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int n = arr.size();
        int currentCount = 1;
        int maxCount = 1;
        
        for(int i=1;i<n;i++){
            
            if(arr[i] == arr[i-1]){
                currentCount++;
                maxCount = max(currentCount, maxCount);
            } else {
                currentCount = 1; // reset the streak
            }
        }
        return maxCount;
    }
};