//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> result;
        vector<bool> used(s.size(), false);
        string current;

        // Sort the string to handle duplicates
        sort(s.begin(), s.end());

        // Helper function for backtracking
        function<void()> backtrack = [&]() {
            if (current.size() == s.size()) {
                result.push_back(current);
                return;
            }

            for (int i = 0; i < s.size(); i++) {
                // Skip already used characters
                if (used[i]) continue;

                // Skip duplicates: pick the first unused instance of each duplicate character
                if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

                // Choose the current character
                used[i] = true;
                current.push_back(s[i]);

                // Recurse
                backtrack();

                // Undo the choice (backtrack)
                current.pop_back();
                used[i] = false;
            }
        };

        backtrack();
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends