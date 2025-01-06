//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
    int n = arr.size();
    
    if (n < 2) {
        return {};  // Return an empty array if there are fewer than two elements
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    int closestSum = INT_MAX;
    vector<int> result;

    // Iterate with two pointers
    while (left < right) {
        int currentSum = arr[left] + arr[right];

        // Check if this sum is closer to the target
        if (abs(target - currentSum) < abs(target - closestSum)) {
            closestSum = currentSum;
            result = {arr[left], arr[right]};
        }
        // If sums are equally close, choose the one with the maximum absolute difference
        else if (abs(target - currentSum) == abs(target - closestSum)) {
            if (abs(arr[right] - arr[left]) > abs(result[1] - result[0])) {
                result = {arr[left], arr[right]};
            }
        }

        // Move pointers
        if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }

    return result;
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends