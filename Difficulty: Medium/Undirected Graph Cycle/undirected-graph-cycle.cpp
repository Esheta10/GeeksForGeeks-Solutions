class Solution {
public:
    bool dfs(int u, int parent, vector<int> adj[], vector<int>& vis) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (vis[v]) return true;
            if (dfs(v, u, adj, vis)) return true;
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
            if (!vis[i] && dfs(i, -1, adj, vis)) return true;
        }
        return false;
    }
};
