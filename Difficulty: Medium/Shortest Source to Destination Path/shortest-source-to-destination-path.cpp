// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 || A[X][Y] == 0)
            return -1;
            
        if(N == X && M == Y)
            return 0;
            
        queue<vector<int>> que;
        que.push({0,0, 0});
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        visited[0][0] = true;
        
        while(!que.empty()){
            
            vector<int> current = que.front();
            que.pop();
            
            int row = current[0];
            int col = current[1];
            int dist = current[2];
            
            if(row == X && col == Y)
                return dist;
             
            // up   
            int newRow  = row-1;
            int newCol = col;
            
            if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M 
            && A[newRow][newCol] == 1 && !visited[newRow][newCol]){
                que.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = 1;
            }
            // down
            newRow  = row+1;
            newCol = col;
            
            if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M 
            && A[newRow][newCol] == 1 && !visited[newRow][newCol]){
                que.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = 1;
            }
            // left
            newRow  = row;
            newCol = col-1;
            
            if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M 
            && A[newRow][newCol] == 1 && !visited[newRow][newCol]){
                que.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = 1;
            }
            // down
            newRow  = row;
            newCol = col+1;
            
            if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M 
            && A[newRow][newCol] == 1 && !visited[newRow][newCol]){
                que.push({newRow, newCol, dist+1});
                visited[newRow][newCol] = 1;
            }
        }
        return -1;
    }
};