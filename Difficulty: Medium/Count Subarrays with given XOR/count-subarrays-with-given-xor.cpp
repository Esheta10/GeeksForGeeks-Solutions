//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
    unordered_map<int, int> prefixXorCount;
    int count = 0;
    int prefixXor = 0;

    // Initialize the hash map with 0 to handle subarrays starting from index 0
    prefixXorCount[0] = 1;

    for (int num : arr) {
        prefixXor ^= num;

        // Compute the required XOR
        int requiredXor = prefixXor ^ k;

        // Check if the required XOR exists in the map
        if (prefixXorCount.find(requiredXor) != prefixXorCount.end()) {
            count += prefixXorCount[requiredXor];
        }

        // Update the hash map with the current prefix XOR
        prefixXorCount[prefixXor]++;
    }

    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends