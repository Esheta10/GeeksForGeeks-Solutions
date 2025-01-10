//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();
    vector<int> result;
    unordered_map<int, int> freq_map;

    // Process the first window
    for (int i = 0; i < k; i++) {
        freq_map[arr[i]]++;
    }
    result.push_back(freq_map.size());

    // Slide the window
    for (int i = k; i < n; i++) {
        // Add the new element to the window
        freq_map[arr[i]]++;

        // Remove the element going out of the window
        int prev_element = arr[i - k];
        if (freq_map[prev_element] == 1) {
            freq_map.erase(prev_element);
        } else {
            freq_map[prev_element]--;
        }

        // Add the count of distinct elements to the result
        result.push_back(freq_map.size());
    }

    return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
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
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends