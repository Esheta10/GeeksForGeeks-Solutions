class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int n = arr.size();
        int max_profit=0;
       
       for(int i=1;i<n;i++)
       {
           if(arr[i]>arr[i-1])
                max_profit += arr[i]-arr[i-1];
       }
       return max_profit;
    }
};