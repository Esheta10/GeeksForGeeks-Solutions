//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int temp=n,rem;
        int count=0;
        while(temp>0)
        {
            count++;
            temp=temp/10;
        }
        int sum=0;
        temp=n;
        while(temp>0)
        {
            rem=temp%10;
            sum=sum+pow(rem,count);
            temp=temp/10;
        }
        if(sum==n)
            return "true";
        else
            return "false";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends