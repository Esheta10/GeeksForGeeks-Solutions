class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int totalFlips = 0;
        vector<bool> flipStartedHere(n, false);
        int currentFlipCount = 0;
        
        for(int i=0; i<n; i++){
            
            if(i>=k && flipStartedHere[i-k] == true)
                currentFlipCount--;
                
            int realValue = (currentFlipCount % 2 == 0) ? arr[i] : 1-arr[i];
            
            if(realValue == 0){
                if(i+k > n)
                    return -1;
                    
                flipStartedHere[i] = true;
                currentFlipCount++;
                totalFlips++;
            }
        }
        return totalFlips;
    }
};