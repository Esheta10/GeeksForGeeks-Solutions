//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int> result;
    if (mat.empty() || mat[0].empty()) return result;
    
    int n = mat.size();    // Number of rows
    int m = mat[0].size(); // Number of columns
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top boundary
        for (int i = left; i <= right; ++i) {
            result.push_back(mat[top][i]);
        }
        top++; // Move the top boundary downward

        // Traverse from top to bottom along the right boundary
        for (int i = top; i <= bottom; ++i) {
            result.push_back(mat[i][right]);
        }
        right--; // Move the right boundary leftward

        if (top <= bottom) {
            // Traverse from right to left along the bottom boundary
            for (int i = right; i >= left; --i) {
                result.push_back(mat[bottom][i]);
            }
            bottom--; // Move the bottom boundary upward
        }

        if (left <= right) {
            // Traverse from bottom to top along the left boundary
            for (int i = bottom; i >= top; --i) {
                result.push_back(mat[i][left]);
            }
            left++; // Move the left boundary rightward
        }
    }
    
    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends