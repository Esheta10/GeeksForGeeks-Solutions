//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
         unordered_map<int, int> prefix_sum_map; // Stores prefix_sum and its index
    int prefix_sum = 0;
    int max_length = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefix_sum += arr[i];

        // Check if the current prefix_sum equals k
        if (prefix_sum == k) {
            max_length = i + 1; // Subarray starts from index 0
        }

        // Check if there is a prefix_sum that matches (prefix_sum - k)
        if (prefix_sum_map.find(prefix_sum - k) != prefix_sum_map.end()) {
            max_length = max(max_length, i - prefix_sum_map[prefix_sum - k]);
        }

        // Store the first occurrence of the prefix_sum
        if (prefix_sum_map.find(prefix_sum) == prefix_sum_map.end()) {
            prefix_sum_map[prefix_sum] = i;
        }
    }

    return max_length;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends