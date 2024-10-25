//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
    sort(arr.begin(), arr.end());

    int n = arr.size();
    vector<int> result(n);  // To store the rearranged array

    int left = 0;          // Pointer to smallest element
    int right = n - 1;     // Pointer to largest element
    bool toggle = true;    // To alternate between largest and smallest

    for (int i = 0; i < n; ++i) {
        if (toggle) {
            result[i] = arr[right--];  // Take the largest element
        } else {
            result[i] = arr[left++];   // Take the smallest element
        }
        toggle = !toggle;  // Flip between true and false
    }

    return result;
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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends