//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
    int n = arr.size();
    
    // Check if kth missing is beyond the last element of the array
    int missing = arr[n - 1] - n;
    if (missing < k) {
        return arr[n - 1] + (k - missing);
    }
    
    // Binary search to find the first index where missing[i] >= k
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        missing = arr[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    // Calculate the kth missing number
    return arr[low - 1] + (k - (arr[low - 1] - low));
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends