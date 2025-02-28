//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;

        for (string token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop top two elements
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                // Perform the operation
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // Integer division

            } else {
                // Convert string to integer and push onto stack
                st.push(stoi(token));
            }
        }

        return st.top(); // Final result
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends