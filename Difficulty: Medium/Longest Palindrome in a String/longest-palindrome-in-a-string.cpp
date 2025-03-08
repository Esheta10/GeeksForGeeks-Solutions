//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
       int n = s.size();
        if (n == 0) return "";
        
        int start = 0, maxLength = 1;

        // Function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currentLength = right - left + 1;
                if (currentLength > maxLength) {
                    start = left;
                    maxLength = currentLength;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd-length palindrome (single center)
            expandAroundCenter(i, i);
            // Even-length palindrome (two-center)
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
}; 
   

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends