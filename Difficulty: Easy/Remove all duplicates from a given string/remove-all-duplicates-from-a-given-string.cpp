//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
     // Create an array to mark the presence of characters
        std::vector<bool> visited(256, false);  // ASCII size, supports all characters
        int len = str.length();
        int index = 0;  // Pointer for the result string
        
        // Traverse through the input string
        for (int i = 0; i < len; i++) {
            // If the character is not visited, append it to result
            if (!visited[(int)str[i]]) {
                visited[(int)str[i]] = true;  // Mark character as visited
                str[index++] = str[i];        // Append character
            }
        }
        
        // Resize the string to the new length (index)
        str.resize(index);
        return str;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends