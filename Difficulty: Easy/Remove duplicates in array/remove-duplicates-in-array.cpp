//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
    unordered_set<int> uniqueElements;  // Set to track unique elements
    vector<int> result;                  // Result vector to store unique elements

    for (const int& num : arr) {
        // If the number is not already in the set, add it to both the set and the result
        if (uniqueElements.find(num) == uniqueElements.end()) {
            uniqueElements.insert(num);
            result.push_back(num);
        }
    }

    return result;  // Return the vector containing unique elements
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
        Solution obj;
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends