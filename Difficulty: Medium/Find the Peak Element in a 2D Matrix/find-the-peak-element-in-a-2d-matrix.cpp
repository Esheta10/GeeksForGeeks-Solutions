class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        
        int left = 0;
        int right = cols - 1;
        
        while(left <= right){
            
            int midCol = left + (right - left)/2;
            
            int maxRow = 0;
            for(int row = 0; row<rows; row++){
                if(mat[row][midCol] > mat[maxRow][midCol])
                    maxRow = row;
            }
            
            int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : INT_MIN;
            int rightVal = (midCol < cols-1) ? mat[maxRow][midCol + 1] : INT_MIN;
            
            int currVal = mat[maxRow][midCol];
            
            if(currVal >= leftVal && currVal >= rightVal)
                return {maxRow, midCol};
            else if(currVal < leftVal)
                right = midCol - 1;
            else
                left = midCol + 1;
        }
        return {-1,-1};
    }
};
