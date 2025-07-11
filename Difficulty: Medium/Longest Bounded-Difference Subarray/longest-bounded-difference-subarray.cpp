//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
    
    int left = 0, max_len = 0, best_start = 0;
    multiset<int> window;

    for (int right = 0; right < arr.size(); right++) {
        window.insert(arr[right]);

        // Shrink the window if the max-min difference exceeds x
        while (*window.rbegin() - *window.begin() > x) {
            window.erase(window.find(arr[left]));
            left++;
        }

        // Update the maximum length and starting index
        if (right - left + 1 > max_len) {
            max_len = right - left + 1;
            best_start = left;
        }
    }

    // Extract the longest valid subarray
    return vector<int>(arr.begin() + best_start, arr.begin() + best_start + max_len);
        
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
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends