class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Build adjacency list from edges
        unordered_map<int, vector<pair<int,int>>> adj;
        
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // For undirected graph
        }
        
        // Step 2: Initialize min heap and result array
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> result(V, INT_MAX);
        vector<bool> visited(V, false); // ✅ Add visited array
        
        result[src] = 0;
        pq.push({0, src});
        
        // Step 3: Dijkstra's algorithm
        while(!pq.empty()) {
            
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // ✅ Skip if already visited (KEY OPTIMIZATION)
            if(visited[node]) {
                continue;
            }
            visited[node] = true;
            
            // Explore all neighbors
            for(auto &neighbor : adj[node]) {
                
                int adjNode = neighbor.first;
                int wt = neighbor.second;
                
                // ✅ Only process unvisited nodes
                if(!visited[adjNode] && d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        
        return result;
    }
};