//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to check if it is feasible to place cows with at least `distance` apart
    bool isFeasible(vector<int>& stalls, int k, int distance) {
    int count = 1; // Place the first cow in the first stall
    int last_position = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_position >= distance) {
            count++;
            last_position = stalls[i];
            if (count == k) { // If all cows are placed
                return true;
            }
        }
    }
    return false;
}

// Function to find the maximum minimum distance
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
    sort(stalls.begin(), stalls.end()); // Sort the stalls

    int low = 1; // Minimum possible distance
    int high = stalls.back() - stalls.front(); // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2; // Midpoint of the current search space
        
        if (isFeasible(stalls, k, mid)) {
            result = mid; // Update result with the current feasible distance
            low = mid + 1; // Try for a larger distance
        } else {
            high = mid - 1; // Try for a smaller distance
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

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends