class Solution {
  public:
    int countLessEqual(vector<int>& row, int target){
        int count=0;
        
        for(int num: row){
            if(num<=target)
                count++;
            else
                break;
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        
        int low = mat[0][0]; // first element of first row
        int high = mat[0][col-1]; // last element of first row;
        
        for(int i=0; i<row; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][col-1]);
        }
        
        
        int medianPos = (row * col + 1)/2;
        
        while(low < high){
            
            int mid = low + (high - low)/2;
            
            int count = 0;
            for(int i=0; i<row; i++)
                count += countLessEqual(mat[i], mid);
        
            if(count < medianPos)
                low = mid+1;
            else
                high = mid;
       }
       return low;
    }
};
