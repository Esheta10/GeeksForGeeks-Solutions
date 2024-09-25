//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
                int n = arr.size();
        if (n <= 1) return 0; // No jumps needed if array has one or zero elements
        if (arr[0] == 0) return -1; // If the first element is 0, we cannot jump anywhere
        
        int jumps = 0; // Count of jumps
        int currentEnd = 0; // End of current jump range
        int farthest = 0; // Farthest point reachable

        for (int i = 0; i < n - 1; i++) { // Iterate till the second last element
            farthest = max(farthest, i + arr[i]); // Update the farthest point

            if (i == currentEnd) { // If we've reached the end of the current jump
                jumps++; // Increment jump count
                currentEnd = farthest; // Update the end of current jump range
                if (currentEnd >= n - 1) break; // Break if we can reach the end
            }

            // If we cannot proceed further
            if (currentEnd <= i && arr[i] == 0) return -1; 
        }

        return jumps; // Return the total number of jumps

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends