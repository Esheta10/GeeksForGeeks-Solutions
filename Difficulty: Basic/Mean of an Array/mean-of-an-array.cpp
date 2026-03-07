class Solution {
  public:
    int findMean(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int num : arr)
            sum += num;
            
        int mean = sum / n;
    
    }
};