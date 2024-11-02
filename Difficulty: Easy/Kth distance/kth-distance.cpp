//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_set<int> elements;

    for (int i = 0; i < arr.size(); ++i) {
        // Check if current element is already in the set
        if (elements.find(arr[i]) != elements.end()) {
            return true; // Duplicate within k distance found
        }

        // Insert current element into the set
        elements.insert(arr[i]);

        // Remove the element that's k distance away
        if (i >= k) {
            elements.erase(arr[i - k]);
        }
    }

    return false; // No duplicates within k distance found
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends