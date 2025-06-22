

class Solution {
  public:
    int maxsum_SIS(int arr[], int n) {
        // Your code goes here
        int maxSum = 0;
        for(int i=0;i<n;i++)
        {
            int sum = arr[i];
            int j=i+1;
            while(j<n && arr[j]>arr[j-1])
            {
                sum += arr[j];
                j++;
            }
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};