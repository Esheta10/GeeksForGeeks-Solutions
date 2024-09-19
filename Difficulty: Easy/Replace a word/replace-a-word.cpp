//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string replaceAll(string str, string oldW, string newW) {
        // code here
        int pos=0;
        while((pos=str.find(oldW,pos))!=string::npos)
        {
            str.replace(pos,oldW.length(),newW);
            pos += newW.length();
        }
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string S, oldW, newW;
        getline(cin, S);
        getline(cin, oldW);
        getline(cin, newW);
        Solution ob;
        cout << ob.replaceAll(S, oldW, newW) << endl;
    }
    return 0;
}

// } Driver Code Ends