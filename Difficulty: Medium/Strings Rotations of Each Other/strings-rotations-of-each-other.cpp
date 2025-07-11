//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string& s1, string& s2) {
        // Your code here
        // Check if both strings are of equal length
    if (s1.length() != s2.length()) {
        return false;
    }
    
    // Concatenate s1 with itself
    string temp = s1 + s1;

    // Check if s2 is a substring of the concatenated string
    return (temp.find(s2) != string::npos);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.areRotations(s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends