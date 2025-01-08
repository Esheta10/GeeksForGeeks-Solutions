//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
    int count = 0;

    // Sort the array to make checking easier
    sort(arr.begin(), arr.end());

    // Iterate through each element as the largest side
    for (int k = 2; k < n; ++k) {
        int i = 0, j = k - 1;

        // Use two pointers to find pairs of sides
        while (i < j) {
            // If arr[i] + arr[j] > arr[k], we can form a triangle
            if (arr[i] + arr[j] > arr[k]) {
                count += (j - i); // All pairs between i and j form valid triangles with arr[k]
                j--; // Move j to the left to check for other pairs
            } else {
                i++; // Move i to the right if the sum is too small
            }
        }
    }

    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends