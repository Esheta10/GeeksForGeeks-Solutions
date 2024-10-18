//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        // do modify in the given array
    // Step 1: Decrease all values by 1 to handle 1-based indexing.
    for (int i = 0; i < N; i++) {
        arr[i]--;
    }

    // Step 2: Use elements of arr[] as index and increase corresponding elements by n.
    for (int i = 0; i < N; i++) {
        if (arr[i] % P < N) {
            arr[arr[i] % P] += P;
        }
    }

    // Step 3: Compute the frequency of each element in the modified array.
    for (int i = 0; i < N; i++) {
        arr[i] = arr[i] / P;
    }
    }
};


//{ Driver Code Starts.

int main() {
    long long t;

    // testcases
    cin >> t;

    while (t--) {

        int N, P;
        // size of array
        cin >> N;

        vector<int> arr(N);

        // adding elements to the vector
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> P;
        Solution ob;
        // calling frequncycount() function
        ob.frequencyCount(arr, N, P);

        // printing array elements
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends