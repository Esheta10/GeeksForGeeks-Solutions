class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // Step-1: Build adjacency list from edge list
        unordered_map<int, vector<pair<int,int>>> adj;
        
        for(auto &edge : edges){
            int u = edge[0];    // starting node
            int v = edge[1];    // ending node
            int wt = edge[2];   // edge weight
            
            
            // Undirected graph
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // Step-2: Initialize data structures
        //2.a min heap {distance, node}
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq; 
        
        //2.b result array - (har node tak ka shortest distance store karega)
        vector<int> result(V, INT_MAX);
        
        //2.c visited array - har node ko sirf ek baar process karne ke liye
        vector<bool> visited(V, false);
        
        //2.d Initialize data structures
        result[src] = 0;
        pq.push({0,src});
        
        // Step-3: Dijkstra's Algorithm main loop
        while(!pq.empty()){
            
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // agar ye node pehle se visited hai, skip karo
            if(visited[node])
                continue;
                
            visited[node] = true; // mark this node as visited
            
            // Step-4: Process all neighbours
            for(auto &neighbor: adj[node]){
                
                int adjNode = neighbor.first; // neighbor node
                int wt = neighbor.second; /// edge weight to neighbor
                
                // agar current path se neighbor ko visit karna better hai toh distance update karo & min heap mein add karo
                if(!visited[adjNode] && d+wt < result[adjNode]){
                    result[adjNode] = d+wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }
        return result;
    }
};