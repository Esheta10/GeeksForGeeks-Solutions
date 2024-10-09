//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long totalSubarrays = 0;
    long long count_zeros = 0;
    
    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count_zeros++;  // Count consecutive 0's
        } else {
            // When a '1' is encountered, calculate the subarrays formed by the consecutive 0's
            totalSubarrays += (count_zeros * (count_zeros + 1)) / 2;
            count_zeros = 0;  // Reset the counter
        }
    }
    
    // If the array ends with 0's, we need to handle the remaining subarrays
    totalSubarrays += (count_zeros * (count_zeros + 1)) / 2;
    
    return totalSubarrays;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends