// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        int startRow = source.first;
        int startCol = source.second;
        
        int endRow = destination.first;
        int endCol = destination.second;
        
        if(grid[startRow][startCol] == 0 || grid[endRow][endCol] == 0)  // start and end are blocked
            return -1;
            
        if(startRow == endRow && startCol == endCol)
            return 0; // start and end are same
            
        // queue banao
        queue<vector<int>> q;
        q.push({startRow, startCol, 0});    // starting position daalo
        
        // visited array--> taaki cells dobara na jaayein
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        visited[startRow][startCol] = true; // start ko true mark karo
        
        while(!q.empty()){
            
            vector<int> current = q.front();
            q.pop();
            
            int row = current[0];
            int col = current[1];
            int dist = current[2];
            
            
            if(row == endRow && col == endCol)
                return dist;// destination pahunch gaye
                
            // check directions
            // UP jao
            int newRow = row - 1;
            int newCol = col;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
            && grid[newRow][newCol] == 1 && !visited[newRow][newCol]){
                q.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = true;
                
            }
            
            // DOWN jao
            newRow = row + 1;
            newCol = col;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
            && grid[newRow][newCol] == 1 && !visited[newRow][newCol]){
                q.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = true;
                
            }
            
            // LEFT jao
            newRow = row;
            newCol = col - 1;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
            && grid[newRow][newCol] == 1 && !visited[newRow][newCol]){
                q.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = true;
                
            }
            
            // RIGHT jao
            newRow = row;
            newCol = col + 1;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
            && grid[newRow][newCol] == 1 && !visited[newRow][newCol]){
                q.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = true;
                
            }
        }
        
        return -1;
    }
};
