// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m = arr.size();
        int n = arr[0].size();
        
        int maxRow = -1;
        int maxCount = 0;
        
        // check each row
        for(int i=0; i<m; i++){
            
            int count = 0;
            // count 1's in each row
            for(int j=0; j<n; j++){
                if(arr[i][j] == 1){
                    count++;
                }
                // update if this row has more 1's
                if(count > maxCount){
                    maxCount = count;
                    maxRow = i;
                }
            }
        }
        return maxRow;
    }
};