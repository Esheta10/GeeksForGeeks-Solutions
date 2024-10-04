//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
     unordered_set<char> set;  // Set to store distinct characters
    int left = 0, maxLength = 0;

    for (int right = 0; right <S.length(); ++right) {
        // If the character is already in the set, remove from the left
        while (set.find(S[right]) != set.end()) {
            set.erase(S[left]);
            left++;
        }

        // Insert the current character in the set
        set.insert(S[right]);

        // Update the max length of the distinct substring
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}