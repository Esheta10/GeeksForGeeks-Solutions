//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
          // Check if the input is empty
        if (arr.empty()) return {};

        // Sort intervals by the start time
        sort(arr.begin(), arr.end());

        // Initialize the result with the first interval
        vector<vector<int>> result;
        result.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            // Get the last interval in the result
            vector<int>& last = result.back();

            // Check if the current interval overlaps with the last one
            if (arr[i][0] <= last[1]) {
                // Merge intervals by updating the end time
                last[1] = max(last[1], arr[i][1]);
            } else {
                // No overlap, add the current interval to the result
                result.push_back(arr[i]);
            }
        }

        return result;
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends