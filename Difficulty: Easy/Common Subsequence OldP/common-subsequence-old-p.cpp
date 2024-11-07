//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int commonSubseq(string S1, string S2){
        // code here
        unordered_set<char> set1(S1.begin(),S1.end());
        unordered_set<char> set2(S2.begin(),S2.end());
        
        for(char ch:set1)
        {
            if(set2.find(ch)!=set2.end())
                return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1, S2;
        cin >> S1 >> S2;
        Solution ob;
        cout << ob.commonSubseq(S1, S2) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends