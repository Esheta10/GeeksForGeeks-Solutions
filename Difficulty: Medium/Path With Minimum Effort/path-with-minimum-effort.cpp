class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        // min heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // effort array
       vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        
        vector<vector<int>> directions = {
          {-1,0}, {0,-1}, {0,1}, {1,0} 
        };
        
        pq.push({0,0,0});
        effort[0][0] = 0;
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            int currEffort = curr[0];
            int row = curr[1];
            int col = curr[2];
            
            if(row == n-1 && col == m-1)
                return currEffort;  // reached destination
                    
            if(currEffort > effort[row][col])
                continue; // skip this is an outdated path
            
            for(auto &dir : directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if(newRow < 0 || newRow >=n || newCol < 0 || newCol >=m)
                continue; // out of bounds
                
            int heightsDiff = abs(mat[row][col] - mat[newRow][newCol]);
            
            int newEffort = max(currEffort, heightsDiff); // max jum in entire path
            
            if(newEffort < effort[newRow][newCol]){
                effort[newRow][newCol] = newEffort;
                pq.push({newEffort, newRow, newCol});
            }
          }
        }
        return 0;
    }
};
