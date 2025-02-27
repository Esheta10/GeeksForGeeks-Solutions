//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    stack<int> s, minS;  // Declare the stacks
  public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!s.empty()) {
            if (s.top() == minS.top()) {
                minS.pop();
            }
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        return s.empty() ? -1 : s.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return minS.empty() ? -1 : minS.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends