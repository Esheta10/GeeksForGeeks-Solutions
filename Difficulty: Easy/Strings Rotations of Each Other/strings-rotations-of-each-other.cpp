//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
    string str = "";
    str += s1;
    str += s2;
    int n = str.length()/2;
    vector<int>lps(str.length());
    lps[0] = 0;
    int len = 0;
    int k = 1;
    while(k < str.length()){
        if(str[k] == str[len]){
            len++;
            lps[k] = len;
            k++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[k] = 0;
                k++;
            }
        }
    }
    int rotateLength = lps[str.length()-1];
    int j = 0;
    for(int i = rotateLength; i < n; i++){
        if(s1[i] != s2[j++]){
            return false;
        }
    }
    return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends