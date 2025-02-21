//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> stk;
        // Map to store corresponding pairs of opening and closing brackets
      unordered_map<char, char> bracketMap = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s) {
            if (bracketMap.count(c)) {
                // If the stack is empty or the top element does not match, return false
                if (stk.empty() || stk.top() != bracketMap[c]) {
                    return false;
                }
                stk.pop(); // Pop the matching opening bracket
            } else {
                stk.push(c); // Push opening brackets onto the stack
            }
        }

        // If the stack is empty, all brackets are matched, otherwise, they are not
        return stk.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends