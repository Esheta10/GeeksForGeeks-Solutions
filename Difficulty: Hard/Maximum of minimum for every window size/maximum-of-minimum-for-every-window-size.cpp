//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
     int n = arr.size();
        
        // Next Smaller Element (NSE) and Previous Smaller Element (PSE)
        vector<int> pse(n, -1), nse(n, n);
        
        stack<int> s;
        
        // Find the Previous Smaller Element (PSE) for each element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                pse[i] = s.top();
            }
            s.push(i);
        }

        // Clear the stack to reuse for Next Smaller Element (NSE)
        while (!s.empty()) {
            s.pop();
        }

        // Find the Next Smaller Element (NSE) for each element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nse[i] = s.top();
            }
            s.push(i);
        }
        
        // Array to store the maximum of minimums for each window size
        vector<int> maxOfMin(n + 1, -1);
        
        // For each element, determine the window size it can be the minimum for
        for (int i = 0; i < n; ++i) {
            int len = nse[i] - pse[i] - 1; // The window size where arr[i] is the minimum
            maxOfMin[len] = max(maxOfMin[len], arr[i]);
        }
        
        // Fill the remaining slots of maxOfMin[] by propagating the maximum values
        for (int i = n - 1; i >= 1; --i) {
            maxOfMin[i] = max(maxOfMin[i], maxOfMin[i + 1]);
        }
        
        // The result will be stored in maxOfMin[1..n]
        vector<int> result(maxOfMin.begin() + 1, maxOfMin.end());
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends