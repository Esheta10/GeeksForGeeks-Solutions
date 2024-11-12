//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        // Code here
       unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        // Use a min-heap to keep track of the top k elements by frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (auto& it : mp) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Extract elements from the heap into a result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        // Reverse the result to get the elements in correct order
        reverse(result.begin(), result.end());
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.topKFrequent(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends