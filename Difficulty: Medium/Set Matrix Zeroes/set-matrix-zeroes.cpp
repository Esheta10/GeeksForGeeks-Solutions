//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code hereint n = mat.size();
        int n = mat.size();
    int m = mat[0].size();

    // Variables to track if the first row and first column should be zeroed
    bool firstRowZero = false, firstColZero = false;

    // Check if the first row has any zero
    for (int j = 0; j < m; j++) {
        if (mat[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if the first column has any zero
    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Use the first row and column as markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0; // Mark the row
                mat[0][j] = 0; // Mark the column
            }
        }
    }

    // Update the matrix based on the markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // Handle the first row if needed
    if (firstRowZero) {
        for (int j = 0; j < m; j++) {
            mat[0][j] = 0;
        }
    }

    // Handle the first column if needed
    if (firstColZero) {
        for (int i = 0; i < n; i++) {
            mat[i][0] = 0;
        }
    }

    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends