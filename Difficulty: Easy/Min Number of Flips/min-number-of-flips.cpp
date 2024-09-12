//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n=S.length();
    int start_with_zero=0;//0101010101..
    for(int i=0;i<n;i++)
    {
        if(i%2==0)//even
        {
            if(S[i]=='1')
                start_with_zero++;
        }
        else//odd
        {
            if(S[i]=='0')
                start_with_zero++;
        }
    }
        int start_with_one=n-start_with_zero;   
        return min(start_with_one,start_with_zero); 
    
}