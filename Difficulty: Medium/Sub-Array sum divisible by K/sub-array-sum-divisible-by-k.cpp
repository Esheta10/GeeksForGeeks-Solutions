//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    long long subCount(vector<int>& arr, int k) {
        // Your code goes here
         unordered_map<int, int> remainderMap;
        remainderMap[0] = 1; // Handle the case where the entire subarray is divisible by k
        
        int prefixSum = 0;
        long long count = 0;

        for (int i = 0; i < arr.size(); i++) {
            // Calculate the prefix sum
            prefixSum += arr[i];

            // Calculate remainder of the current prefix sum with k
            int remainder = prefixSum % k;
            
            // Convert negative remainder to positive (standard modulo handling)
            if (remainder < 0) remainder += k;

            // If the remainder has been seen before, it means there's a subarray
            // whose sum is divisible by k
            if (remainderMap.find(remainder) != remainderMap.end()) {
                count += remainderMap[remainder];
            }

            // Increment the frequency of the current remainder
            remainderMap[remainder]++;
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d
        Solution ob;
        cout << ob.subCount(arr, d);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends