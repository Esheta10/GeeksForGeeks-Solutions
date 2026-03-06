class Solution {
  public:
    int maxOccured(vector<int>& L, const vector<int>& R) {
        // code here
        int maxVal = *max_element(R.begin(), R.end());
        vector<int> diff(maxVal+2, 0);
        
        for(int i=0; i<L.size(); i++){
            
            diff[L[i]]++;
            diff[R[i] + 1]--;
        }
        
        
        int maxCount = 0;
        int cumSum = 0;
        int result = 0;
        
        for(int i=0; i<=maxVal; i++){
            
            cumSum += diff[i];
            
            if(cumSum > maxCount){
                maxCount = cumSum;
                result = i;
            }
        }
        return result;
    }
};