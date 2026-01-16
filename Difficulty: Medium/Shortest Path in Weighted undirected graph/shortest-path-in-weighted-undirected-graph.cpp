class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // Adjacency List banao
        unordered_map<int, vector<pair<int,int>>> adj;
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> result(n+1, INT_MAX);
        vector<int> parent(n+1, -1);
        vector<bool> visited(n+1, false);
        
        int src = 1;
        result[src] = 0;
        pq.push({0, src});
        
        // Dijkstra's algorithm
        while(!pq.empty()){
            
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(visited[node])
                continue;
                
            visited[node] = true;
            
            for(auto& neighbor : adj[node]){
                
                int adjNode = neighbor.first;
                int wt = neighbor.second;
                
                // ✅ FIX: Check if NEIGHBOR is visited, not current node!
                if(!visited[adjNode] && d+wt < result[adjNode]){
                    
                    result[adjNode] = d+wt;
                    parent[adjNode] = node;
                    
                    pq.push({d+wt, adjNode});
                }
            }
        }
        
        if(result[n] == INT_MAX){
            return {-1};
        }
        
        // Path nikalo - backtracking
        vector<int> path;
        int current = n;
        
        while(current != -1){
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        path.insert(path.begin(), result[n]);
        return path;
    }
};