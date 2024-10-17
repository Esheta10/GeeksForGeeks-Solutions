//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        // Your code here
      long long low = 0, high = n - 1;
    int res = -1;  // Initialize result as -1 to handle the case where floor doesn't exist

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // If v[mid] is less than or equal to x, this could be a floor
        if (v[mid] <= x) {
            res = mid;  // Update result
            low = mid + 1;  // Search in the right half for a larger floor
        } else {
            // If v[mid] is greater than x, search in the left half
            high = mid - 1;
        }
    }

    return res;
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends