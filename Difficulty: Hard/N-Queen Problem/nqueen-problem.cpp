//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> results;
    
    bool isSafe(vector<int> &board, int col, int row) {
        for (int prevCol = 0; prevCol < col; prevCol++) {
            int prevRow = board[prevCol];
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }

    void solveNQueens(vector<int> &board, int col, int n) {
        if (col == n) {
            results.push_back(board);
            return;
        }
        
        for (int row = 1; row <= n; row++) {
            if (isSafe(board, col, row)) {
                board[col] = row;
                solveNQueens(board, col + 1, n);
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        results.clear();
        vector<int> board(n, 0);
        solveNQueens(board, 0, n);
        return results;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends