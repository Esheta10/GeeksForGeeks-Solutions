//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        // Sort intervals by their end times
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int prev_end = INT_MIN; // The end time of the last included interval
    int remove_count = 0;   // Number of intervals to remove

    // Iterate through sorted intervals
    for (const auto& interval : intervals) {
        if (interval[0] >= prev_end) {
            // No overlap, include this interval
            prev_end = interval[1];
        } else {
            // Overlap detected, increment removal count
            remove_count++;
        }
    }

    return remove_count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends