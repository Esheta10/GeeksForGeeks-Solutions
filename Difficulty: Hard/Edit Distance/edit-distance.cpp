//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Base Cases
    for (int i = 0; i <= m; i++) dp[i][0] = i; // Deletions
    for (int j = 0; j <= n; j++) dp[0][j] = j; // Insertions

    // Filling the DP Table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // No change needed
            else
                dp[i][j] = min({dp[i - 1][j - 1] + 1, // Replace
                                dp[i - 1][j] + 1,   // Remove
                                dp[i][j - 1] + 1}); // Insert
        }
    }
    return dp[m][n];

    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends