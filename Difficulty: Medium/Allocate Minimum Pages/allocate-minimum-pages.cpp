//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to check if it is possible to allocate books with a given maximum pages
    bool isPossible(vector<int>& arr, int n, int k, int maxPages) {
    int studentsRequired = 1, currentPages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return false; // A single book has more pages than maxPages
        if (currentPages + arr[i] > maxPages) {
            // Assign to the next student
            studentsRequired++;
            currentPages = arr[i];
            if (studentsRequired > k) return false;
        } else {
            currentPages += arr[i];
        }
    }
    return true;
}
    int findPages(vector<int> &arr, int k) {
        // code here
    int n = arr.size();
    if (k > n) return -1; // Not enough books for each student

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, k, mid)) {
            result = mid; // Update result and try for smaller values
            high = mid - 1;
        } else {
            low = mid + 1; // Try for larger values
        }
    }
    return result;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends