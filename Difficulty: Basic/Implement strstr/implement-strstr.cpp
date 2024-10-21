//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     int n = s.length();   // Length of string s
    int m = x.length();   // Length of string x

    if (m > n) {
        return -1;  // If x is longer than s, it cannot be a substring
    }

    // Loop through the string s
    for (int i = 0; i <= n - m; i++) {
        int j;
        // Check if the substring s[i...i+m-1] matches with x
        for (j = 0; j < m; j++) {
            if (s[i + j] != x[j]) {
                break;  // Break if characters don't match
            }
        }
        // If the entire substring matches, return the starting index
        if (j == m) {
            return i;
        }
    }

    // If no match is found, return -1
    return -1;
}