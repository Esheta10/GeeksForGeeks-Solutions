//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int getCarries(string N , string M) {
        // code here
        int carry=0;
        int carryCount=0;
        int sum=0;
        int lenM=M.length();
        int lenN=N.length();
        
         int maxLength=max(lenM,lenN);
         
        // Pad shorter string with leading zeros
        N = string(maxLength - lenN, '0') + N;
        M = string(maxLength - lenM, '0') + M;
        
        for(int i=maxLength;i>=0;i--)
        {
            int digit1=M[i]-'0';
            int digit2=N[i]-'0';
        
            sum=digit1+digit2+carry;
            if(sum>=10)
            {
                carryCount++;
                carry=1;
            }
            else
            {
                carry=0;
            }
        }
        return carryCount;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.getCarries(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends