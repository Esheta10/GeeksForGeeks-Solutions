//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    bool passed (string s) {
        //code here.
        int n=s.length();
        int mid=n/2;
    
        
        //frequency maps for left and right halves
        unordered_map<char,int> countLeft,countRight;
        
        //if the string length is odd,ignore the middle character
        int i=0,j=(n%2==0) ? mid : mid+1;
        
        //count the frequency of characters in both halves
        while(i<mid)
        {
            countLeft[s[i]]++;
            countRight[s[j]]++;
            i++;
            j++;
        }
        return countLeft==countRight;
       
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        if (ob.passed (s))
            cout << "YES\n";
        else
            cout << "NO\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends