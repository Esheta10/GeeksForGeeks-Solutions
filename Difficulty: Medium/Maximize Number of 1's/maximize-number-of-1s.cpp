class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int left = 0;
        int best_streak = 0;
        int zeros = 0;
        
        for(int right = 0; right < n; right++){
            
            if(arr[right] == 0)
                zeros++;
                
            if(zeros > k){ // shrink the window
                if(arr[left] == 0)
                    zeros--;
                    
                left++;
            }
            
            best_streak = max(best_streak, right-left+1);
        }
        return best_streak;
    }
};
