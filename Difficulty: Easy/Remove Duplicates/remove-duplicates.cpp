//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        unordered_set<char> seen;
        string result;
        
        for(char c: str)
        {
            if(seen.find(c)==seen.end())
            {
                result.push_back(c);
                seen.insert(c);
            }
        }
        return result;
    }
};
/*The insert function adds an element to the unordered_set.
If the element already exists in the set, the insertion has no effect 
(i.e., it does not add the element again). 
This ensures that each element in the set is unique.*/

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends