//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
    int totalSum = 0, leftSum = 0;
    for (int num : arr) {
        totalSum += num; // Calculate total sum
    }

    for (int i = 0; i < arr.size(); i++) {
        totalSum -= arr[i]; // Update right sum by excluding current element

        if (leftSum == totalSum) {
            return i; // Equilibrium point found
        }

        leftSum += arr[i]; // Update left sum
    }

    return -1; // No equilibrium point found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends