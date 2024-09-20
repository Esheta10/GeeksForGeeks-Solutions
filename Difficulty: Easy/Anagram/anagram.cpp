//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b) {

        // Your code here
        //{ Driver Code Starts

        if (a.length() != b.length())
            return false;

        // Create frequency arrays for both strings
        vector<int> countA(26, 0), countB(26, 0);

        // Count frequency of characters in both strings
        for (int i = 0; i < a.length(); i++) {
            countA[a[i] - 'a']++;
            countB[b[i] - 'a']++;
        }

        // Compare the frequency arrays
        return countA == countB;
    }
};



//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// } Driver Code Ends