//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
    int n=arr.size();
    //segregate positive and non-positive numbers
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    // Step 2: Mark presence of numbers in the positive portion
    for (int i = j; i < n; ++i) {
        int val = abs(arr[i]); // Take absolute value (to handle already marked numbers)
        if (val - 1 + j < n && arr[val - 1 + j] > 0) {
            arr[val - 1 + j] = -arr[val - 1 + j]; // Mark index as visited by making it negative
        }
    }

    // Step 3: Find the first positive index
    for (int i = j; i < n; ++i) {
        if (arr[i] > 0) {
            return i - j + 1; // Missing number is 1-based index of the first positive value
        }
    }

    // If all numbers are present
    return n - j + 1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends