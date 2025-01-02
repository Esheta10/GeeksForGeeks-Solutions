//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
         // Map to store the frequency of prefix sums
    unordered_map<int, int> prefix_sum_map;
    // Initialize with 0 sum having frequency 1 to account for subarrays starting from index 0
    prefix_sum_map[0] = 1;
    
    int current_sum = 0; // To keep track of the current prefix sum
    int count = 0; // To store the number of valid subarrays
    
    // Traverse the array
    for (int num : arr) {
        // Update the current prefix sum
        current_sum += num;
        
        // Check if current_sum - k is in the map, if it is, it means we have found a valid subarray
        if (prefix_sum_map.find(current_sum - k) != prefix_sum_map.end()) {
            count += prefix_sum_map[current_sum - k];
        }
        
        // Update the frequency of the current prefix sum in the map
        prefix_sum_map[current_sum]++;
    }
    
    return count;
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
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends