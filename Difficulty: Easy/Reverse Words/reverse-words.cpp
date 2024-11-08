//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stringstream ss(str);
        string token;
        vector<string> words;
        
        // Extract words from the stringstream and store them in the vector
        while (getline(ss, token, '.')) {
            words.push_back(token);
        }
        
        // Rebuild the string with the reversed word order
        string result = "";
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i != 0) result += ".";  // Add a dot after each word except the last one
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
        cout << obj.reverseWords(s) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends