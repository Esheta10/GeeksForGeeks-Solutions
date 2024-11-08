//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
    unordered_set<char> setA(A.begin(), A.end());  // Set of characters in A
    unordered_set<char> setB(B.begin(), B.end());  // Set of characters in B

    // Find the symmetric difference: characters in A or B but not both
    unordered_set<char> result;
    for (char c : setA) {
        if (setB.find(c) == setB.end()) {
            result.insert(c);
        }
    }
    for (char c : setB) {
        if (setA.find(c) == setA.end()) {
            result.insert(c);
        }
    }

    // If no uncommon characters found, return "-1"
    if (result.empty()) {
        return "-1";
    }

    // Convert result set to a sorted string
    string res(result.begin(), result.end());
    sort(res.begin(), res.end());

    return res;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends