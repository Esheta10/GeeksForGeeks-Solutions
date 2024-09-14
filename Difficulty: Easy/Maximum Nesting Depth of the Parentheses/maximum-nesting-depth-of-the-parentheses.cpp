//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        stack<char> st;
        int result=0;
        for(char &ch:s)
        {
            if(ch=='(')
                st.push(ch);
            else if(ch==')')
                st.pop();
                
            result=max(result,(int)st.size());//size_t
        
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends