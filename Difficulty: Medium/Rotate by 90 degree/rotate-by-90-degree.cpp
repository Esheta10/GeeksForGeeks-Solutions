class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        
        vector<vector<int>> result(n, vector<int>(n));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                result[n - 1 - c][r] = mat[r][c];
            }
        }

        mat = result;  // Copy back
        
    }
};
