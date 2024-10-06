//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> leaders;
    
    // Step 1: Start with the last element as it is always a leader
    int max_from_right = arr[n-1];
    leaders.push_back(max_from_right);  // The last element is always a leader
    
    // Step 2: Traverse the array from second-last to first element
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= max_from_right) {
            leaders.push_back(arr[i]);  // Add to the leaders list
            max_from_right = arr[i];    // Update max_from_right
        }
    }
    
    // Step 3: Reverse the leaders list since we collected them in reverse order
    reverse(leaders.begin(), leaders.end());  // Reverse to correct the order
    
    return leaders;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends