//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> strStack;  // Stores substrings
    stack<int> numStack;     // Stores repeat counts
    string result = "";
    string num = "";         // Stores multi-digit numbers

    for (char c : s) {
        if (isdigit(c)) {
            num += c; // Handling multi-digit numbers
        } else if (c == '[') {
            numStack.push(stoi(num)); // Convert and store number
            num = ""; // Reset for next number
            strStack.push(result); // Store current result
            result = ""; // Reset for new inner content
        } else if (c == ']') {
            string temp = result;
            int repeat = numStack.top();
            numStack.pop();
            
            result = strStack.top();
            strStack.pop();
            
            while (repeat--) {
                result += temp;
            }
        } else {
            result += c; // Append normal characters
        }
    }
    return result;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends