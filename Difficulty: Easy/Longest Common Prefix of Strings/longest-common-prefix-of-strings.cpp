//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if (arr.empty()) return "-1";  // If the array is empty, return "-1"
    
    // Initialize the prefix with the first string
    string prefix = arr[0];
    
    // Loop over the array to check the common prefix
    for (int i = 1; i < arr.size(); i++) {
        int j = 0;
        // Compare current string and prefix character by character
        while (j < prefix.length() && j < arr[i].length() && prefix[j] == arr[i][j]) {
            j++;
        }
        // Reduce the prefix size up to the matched characters
        prefix = prefix.substr(0, j);
        // If at any point the prefix becomes empty, no common prefix exists
        if (prefix.empty()) {
            return "-1";
        }
    }
    
    return prefix;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends