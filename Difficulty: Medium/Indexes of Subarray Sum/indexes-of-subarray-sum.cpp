//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
        // Traverse the array
        int left = 0;
        long long curr_sum=0;
        for (int right = 0; right < n; right++) {
        // Add the current element to the current sum
        curr_sum += arr[right];

        // If current sum exceeds the desired sum, reduce the window size from the left
        while (curr_sum > s && left < right) {
            curr_sum -= arr[left];
            left++;
        }

        // If current sum equals the desired sum, return the indices (1-based)
        if (curr_sum == s) {
            return {left + 1, right + 1};
        }
    }

    // If no subarray is found, return -1
    return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends