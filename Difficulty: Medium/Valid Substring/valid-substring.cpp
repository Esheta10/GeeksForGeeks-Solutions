//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
    stack<int> stk;
    stk.push(-1); // Base index for valid substring length
    int maxLength = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stk.push(i); // Push the index of the '('
        } else { // s[i] == ')'
            stk.pop(); // Pop the top element
            if (!stk.empty()) {
                // Calculate the length of the valid substring
                maxLength = max(maxLength, i - stk.top());
            } else {
                // No matching opening parenthesis, push the index of ')'
                stk.push(i);
            }
        }
    }

    return maxLength;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends