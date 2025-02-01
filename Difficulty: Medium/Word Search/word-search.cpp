//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<vector<char>>& mat, int i, int j, string& word, int index, vector<vector<bool>>& visited) {
        // Code here
        // Base case: if the entire word is found
        if (index == word.length()) return true;

        int n = mat.size(), m = mat[0].size();

        // Check boundaries, character match, and if already visited
        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != word[index] || visited[i][j]) 
            return false;

        // Mark the current cell as visited
        visited[i][j] = true;

        // Explore all 4 possible directions (up, down, left, right)
        bool found = dfs(mat, i+1, j, word, index+1, visited) ||
                     dfs(mat, i-1, j, word, index+1, visited) ||
                     dfs(mat, i, j+1, word, index+1, visited) ||
                     dfs(mat, i, j-1, word, index+1, visited);

        // Backtrack: unmark the cell before returning
        visited[i][j] = false;

        return found;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Try to find the word starting from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends