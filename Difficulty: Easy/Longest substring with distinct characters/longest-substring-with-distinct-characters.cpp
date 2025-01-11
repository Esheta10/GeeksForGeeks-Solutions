//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_set<char> seen; // To store unique characters
    int maxLength = 0;        // To store the length of the longest substring
    int left = 0;             // Left pointer of the sliding window

    for (int right = 0; right < s.length(); ++right) {
        // If the character is already in the set, slide the left pointer
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]);
            left++;
        }

        // Insert the current character into the set
        seen.insert(s[right]);

        // Update the maximum length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends