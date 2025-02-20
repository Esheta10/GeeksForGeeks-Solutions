//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int>& arr) {
        // Create two heaps
        priority_queue<int> maxHeap;   // Max-heap for the smaller half (inverted)
        priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap for the larger half
        
        vector<double> result;
        
        for (int num : arr) {
            // Step 1: Add the current number
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);  // Add to max-heap
            } else {
                minHeap.push(num);  // Add to min-heap
            }

            // Step 2: Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Step 3: Calculate the median
            if (maxHeap.size() > minHeap.size()) {
                result.push_back((double)maxHeap.top());  // Median is the root of max-heap
            } else {
                result.push_back((maxHeap.top() + minHeap.top()) / 2.0);  // Median is average of roots
            }
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends