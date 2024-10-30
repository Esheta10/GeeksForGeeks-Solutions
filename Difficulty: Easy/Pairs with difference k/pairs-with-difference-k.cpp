//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
    unordered_map<int, int> elementFrequency;
    int count = 0;

    // Store the frequency of each element in the array
    for (int num : arr) {
        elementFrequency[num]++;
    }

    // For each unique element in the array, check if the pair exists
    for (const auto& pair : elementFrequency) {
        int num = pair.first;

        // Check if there's an element that is `num + k`
        if (elementFrequency.count(num + k)) {
            count += elementFrequency[num] * elementFrequency[num + k];
        }
    }

    return count;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends