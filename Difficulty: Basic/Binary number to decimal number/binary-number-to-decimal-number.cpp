//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here.
        int decimalValue=0;
        int power=0;
        for(int i=str.size()-1;i>=0;--i)
        {
            if(str[i]=='1')
                decimalValue =decimalValue+pow(2,power);
                
            ++power;
        }
        return decimalValue;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends