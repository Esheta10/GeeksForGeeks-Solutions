//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        const int MOD = 1e9 + 7; // Define the modulo
        if (n == 0) return 0;
        
       long long a=0;
       long long b=1;
       long long temp=0;
        for(int i=2;i<=n;i++)
        {
            temp=(a+b)%MOD;
            a=b;
            b=temp;
        }
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends