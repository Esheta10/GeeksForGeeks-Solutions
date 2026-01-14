// User function Template for C++

class Solution {
  public:
    void DFS(unordered_map<int,vector<int>>& mp, int u, vector<bool>& visited){
        
        visited[u] = true;
        for(int &v : mp[u]){
            if(!visited[v])
                 DFS(mp,v,visited);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,false);
        
        // make graph
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1)
                    mp[i].push_back(j);
            }
        }
        int count=0;
        //DFS
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(mp,i,visited);
                count++;
            }
        }
        return count;
    }
};