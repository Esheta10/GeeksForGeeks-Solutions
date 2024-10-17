//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    int flipCount1 = 0, flipCount2 = 0;

    // Checking with the pattern starting with '0' (i.e., "010101...")
    for (int i = 0; i < n; i++) {
        // For even index, expected character is '0', for odd index it is '1'
        if (i % 2 == 0 && S[i] != '0') {
            flipCount1++;  // Flip needed
        } else if (i % 2 == 1 && S[i] != '1') {
            flipCount1++;  // Flip needed
        }
    }
    // Checking with the pattern starting with '1' (i.e., "101010...")
    for (int i = 0; i < n; i++) {
        // For even index, expected character is '1', for odd index it is '0'
        if (i % 2 == 0 && S[i] != '1') {
            flipCount2++;  // Flip needed
        } else if (i % 2 == 1 && S[i] != '0') {
            flipCount2++;  // Flip needed
        }
    }

    // Return the minimum number of flips between the two patterns
    return min(flipCount1, flipCount2);
}