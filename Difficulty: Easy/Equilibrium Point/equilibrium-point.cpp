//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        // Your code here
     long long totalSum = 0;
    long long leftSum = 0;

    // Calculate the total sum of the array
    for (long long num : arr) {
        totalSum += num;
    }

    // Iterate through the array to find the equilibrium point
    for (int i = 0; i < arr.size(); i++) {
        // Right sum is total sum minus left sum minus current element
        long long rightSum = totalSum - leftSum - arr[i];

        // Check if left sum equals right sum
        if (leftSum == rightSum) {
            return i + 1;  // Return 1-based index
        }

        // Update left sum for the next iteration
        leftSum += arr[i];
    }

    // If no equilibrium point found, return -1
    return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends