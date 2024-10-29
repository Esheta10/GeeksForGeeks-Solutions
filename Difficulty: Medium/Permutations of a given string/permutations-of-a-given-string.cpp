//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void generatePermutations(string s, int index, set<string>& uniquePermutations) {
    // Base case: If we reach the end of the string, add the permutation to the set
    if (index == s.size()) {
        uniquePermutations.insert(s);
        return;
    }
    
    // Recursively swap each character to generate permutations
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        generatePermutations(s, index + 1, uniquePermutations);
        swap(s[index], s[i]); // Backtrack
    }
}

    vector<string> find_permutation(string s) {
        // Code here there
         // Sort the string to ensure lexicographical order
    sort(s.begin(), s.end());
    
    set<string> uniquePermutations;
    generatePermutations(s, 0, uniquePermutations);

    // Convert set to vector to return
    vector<string> result(uniquePermutations.begin(), uniquePermutations.end());
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
        vector<string> ans = ob.find_permutation(S);
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