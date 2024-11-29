//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
    int i = s1.size() - 1; // Pointer for s1
    int j = s2.size() - 1; // Pointer for s2
    int carry = 0; // Initialize carry to 0
    string result = ""; // To store the result

    // Loop while there are bits in either string or carry
    while (i >= 0 || j >= 0 || carry > 0) {
        int bit1 = (i >= 0) ? s1[i] - '0' : 0; // Get bit from s1 or 0
        int bit2 = (j >= 0) ? s2[j] - '0' : 0; // Get bit from s2 or 0

        int sum = bit1 + bit2 + carry; // Sum of bits and carry
        result = char((sum % 2) + '0') + result; // Append the current bit to result
        carry = sum / 2; // Update carry

        i--; // Move to the next bit in s1
        j--; // Move to the next bit in s2
    }

    // Remove leading zeros from the result
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        return result.substr(pos);
    } else {
        return "0"; // Handle the case where result is all zeros
    }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends