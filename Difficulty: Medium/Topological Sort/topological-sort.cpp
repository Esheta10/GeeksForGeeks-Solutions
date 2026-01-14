class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
      
        vector<int> indegree(V,0);
        
        // 1. Fill indegree
        for(int u=0;u<V;u++){
            
            for(int &v : adj[u]){
                indegree[v]++;
            }
        }
        // 2. fill queue with values whose indegree is 0
        queue<int> que;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                que.push(i);
        }
        
        // 3. Simple BFS
        vector<int> result;
        
        while(!que.empty()){
            
            int u = que.front();
            que.pop();
            result.push_back(u);
            
            for(int &v : adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0)
                    que.push(v);
            }
        }
        return result;
    }
};