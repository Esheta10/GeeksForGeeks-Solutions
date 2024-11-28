//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
    int i = 0;
    long long result = 0;  // Use long long to handle overflow
    int sign = 1;  // Default sign is positive
    
    // Step 1: Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }
    
    // Step 2: Check for a sign
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Step 3: Read the integer part
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');  // Convert char to digit and add to result
        i++;
        
        // Step 4: Check for overflow
        if (result * sign >= INT_MAX) {
            return INT_MAX;
        }
        if (result * sign <= INT_MIN) {
            return INT_MIN;
        }
    }
    
    // Step 5: Return the result with the correct sign
    return result * sign;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends