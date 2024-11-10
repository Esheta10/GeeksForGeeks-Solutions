//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long gcd(long long a,long long b)
  {
      while(b!=0)
      {
          long long temp=b;
          b=a%b;
          a=temp;
      }
      return a;
  }
    long long numGame(long long n) {
        // code here
       const long long MOD=1e9+7;
       long long lcm=1;
       
       for(int i=1;i<=n;i++)
       {
           lcm=(lcm*i)/gcd(lcm,i);
           lcm%=MOD;
       }
        return lcm;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        
        cin>>n;

        Solution ob;
        cout << ob.numGame(n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends