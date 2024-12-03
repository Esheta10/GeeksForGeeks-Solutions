//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
         // Reverse the string
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    // Concatenate the original string, separator and the reversed string
    string combined = s + "#" + s_rev;

    // Compute the LPS array (Longest Prefix Suffix) using KMP algorithm
    int n = combined.size();
    vector<int> lps(n, 0);
    int j = 0;  // length of previous longest prefix suffix

    for (int i = 1; i < n; ++i) {
        while (j > 0 && combined[i] != combined[j]) {
            j = lps[j - 1];  // fall back in the LPS array
        }
        if (combined[i] == combined[j]) {
            j++;
        }
        lps[i] = j;
    }

    // The value in the LPS array at the last index will give us the length of the longest palindromic prefix
    int longest_palindromic_prefix = lps[n - 1];

    // The number of characters to add is the remaining part of the string that does not form part of the palindrome
    return s.size() - longest_palindromic_prefix;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends