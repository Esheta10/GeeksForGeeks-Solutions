// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        int row = 0;
        int col = cols - 1;
        
        while(row < rows && col >= 0){
            
            if(mat[row][col] == x)
                return true;
            else if(mat[row][col] > x)
                col--;
            else
                row++;
        }
        return false;
    }
};