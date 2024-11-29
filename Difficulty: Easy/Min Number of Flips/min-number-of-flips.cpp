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
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    int flipsPattern1 = 0; // Flips to match "010101..."
    int flipsPattern2 = 0; // Flips to match "101010..."
    
    for (int i = 0; i < n; ++i) {
        char expectedPattern1 = (i % 2 == 0) ? '0' : '1'; // Pattern 1: "0101..."
        char expectedPattern2 = (i % 2 == 0) ? '1' : '0'; // Pattern 2: "1010..."
        
        if (S[i] != expectedPattern1) 
            flipsPattern1++; // Count flips for pattern 1
        if (S[i] != expectedPattern2) 
            flipsPattern2++; // Count flips for pattern 2
    }
    
    return min(flipsPattern1, flipsPattern2);
}