class Solution {
public:
    bool bfs(int u,int V, vector<int> adj[], vector<int>& visited) {
        
        queue<pair<int,int>> que;
        que.push({u,-1});
        
        visited[u] = true;
        
        while(!que.empty()){
            
            int curr = que.front().first;
            int parent = que.front().second;
            que.pop();
            
            for(int v : adj[curr]) {         // ✅ FIXED: curr not u
                if(v == parent) continue;    // Skip actual parent
            
                if(visited[v]) return true;  // Back edge = cycle!
            
                visited[v] = true;
                que.push({v, curr});
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i] && bfs(i,V, adj, vis)) return true;
        }
        return false;
    }
};
