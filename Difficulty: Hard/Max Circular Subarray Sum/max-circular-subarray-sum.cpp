//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find maximum circular subarray sum.
    int kadaneMax(const vector<int>& arr)
    {
    int maxSum = INT_MIN, currentSum = 0;
    for (int num : arr) {
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
    }
    int kadaneMin(const vector<int>& arr)
    {
    int minSum = INT_MAX, currentSum = 0;
    for (int num : arr) {
        currentSum = min(num, currentSum + num);
        minSum = min(minSum, currentSum);
    }
    return minSum;
    }
    int circularSubarraySum(vector<int> &arr) {

        // your code here
    int maxNormal = kadaneMax(arr);
    if (maxNormal < 0) // All elements are negative
        return maxNormal;

    int totalSum = 0;
    for (int num : arr)
        totalSum += num;

    int minSubarraySum = kadaneMin(arr);
    int maxCircular = totalSum - minSubarraySum;

    return max(maxNormal, maxCircular);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends