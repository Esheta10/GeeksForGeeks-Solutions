//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
          // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Initialize two pointers
    int i = 0, j = arr.size() - 1;
    int count = 0;

    // Step 3: Use two-pointer approach
    while (i < j) {
        if (arr[i] + arr[j] < target) {
            // All pairs from i to j are valid
            count += (j - i);
            i++;
        } else {
            // Decrease j to reduce the sum
            j--;
        }
    }

    return count;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends