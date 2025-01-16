//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int, int> prefix_map; // Map to store prefix sums
    int prefix_sum = 0;                 // Initialize prefix sum
    int max_len = 0;                    // Maximum length of subarray

    for (int i = 0; i < arr.size(); i++) {
        // Replace 0 with -1
        prefix_sum += (arr[i] == 0) ? -1 : 1;

        // If prefix_sum is 0, update max_len
        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        // If prefix_sum exists in the map, update max_len
        if (prefix_map.find(prefix_sum) != prefix_map.end()) {
            max_len = max(max_len, i - prefix_map[prefix_sum]);
        } else {
            // Otherwise, store the prefix_sum with its index
            prefix_map[prefix_sum] = i;
        }
    }

    return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends