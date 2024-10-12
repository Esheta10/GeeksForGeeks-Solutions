//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        if (n < 0) return -1; // Return -1 for negative inputs

    long long int left = 0, right = n, result = 0;

    while (left <= right) {
        long long int mid = left + (right - left) / 2;

        // Check if mid * mid is equal to n
        if (mid * mid == n) {
            return mid; // Perfect square
        }

        // If mid * mid is less than n, update result and move left
        if (mid * mid < n) {
            result = mid; // Update result to mid
            left = mid + 1; // Move left
        } else {
            right = mid - 1; // Move right
        }
    }

    return result; // Return the floor value of the square root
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends