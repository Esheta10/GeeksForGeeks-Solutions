class Solution {
  public:
    void BFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        
        queue<int> que;
        que.push(u);
        
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()){
            
            int u = que.front();
            que.pop();
            
            for(int &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        
        vector<int> result;
        vector<bool> visited(V,false);
        
        BFS(adj,0,visited,result);
        return result;
        
    }
};