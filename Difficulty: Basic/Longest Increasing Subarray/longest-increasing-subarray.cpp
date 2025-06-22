class Solution {
  public:
    // Function to find the length of longest increasing subarray
    int lenOfLongIncSubArr(vector<int> &arr) {
        // Your code goes here.
        int n = arr.size();
        int result = 0;
        for(int i=0;i<n;i++)
        {
            int incr=1;
            int j=i+1;
            while(j<n && arr[j]>arr[j-1])
            {
                incr++;
                j++;
            }
            result = max({result,incr});
        }
        return result;
    }
};