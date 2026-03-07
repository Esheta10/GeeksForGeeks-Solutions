class Solution {
  public:
    int mean(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int num: arr){
            sum +=num;
        }
        
        int mean = sum / n;
        
        return mean;
    }

    int median(vector<int>& arr) {
        
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int median;
        
        if(n % 2 == 1)  // odd elements
            median = arr[n/2];
        else
            median = (arr[n/2 - 1] + arr[n/2])/2 ;
            
        return median;
        
    }
};
