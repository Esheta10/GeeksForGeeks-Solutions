//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
    if (e == 0) return 1.0;  // Base case: anything raised to 0 is 1
    double result = 1.0;
    bool isNegativeExp = (e < 0);
    if (isNegativeExp) e = -e;  // Convert exponent to positive for processing

    while (e > 0) {
        if (e % 2 == 1) result *= b;  // If exponent is odd, multiply by base
        b *= b;  // Square the base
        e /= 2;  // Reduce exponent by half
    }
    
    return isNegativeExp ? (1.0 / result) : result;  // Handle negative exponents
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends