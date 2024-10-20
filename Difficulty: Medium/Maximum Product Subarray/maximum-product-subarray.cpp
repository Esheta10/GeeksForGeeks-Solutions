//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        // code here
        long long maxProduct = arr[0];
    long long minProduct = arr[0];
    long long result = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        // If current element is negative, swap max and min
        if (arr[i] < 0)
            swap(maxProduct, minProduct);
        
        // Update max and min product for current index
        maxProduct = max((long long)arr[i], maxProduct * arr[i]);
        minProduct = min((long long)arr[i], minProduct * arr[i]);
        
        // Update the global maximum product
        result = max(result, maxProduct);
    }
    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends