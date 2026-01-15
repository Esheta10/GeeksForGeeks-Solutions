class Solution {
  public:
    bool checkBipartite(vector<int> adj[], int curr, vector<int>& color, int currColor){
        
        color[curr] = currColor;
        
        for(int &v: adj[curr]){
            
            if(color[v] == color[curr])
                return false;
                
            if(color[v] == -1){
                
                int colorOfV = 1 - currColor;
                if(checkBipartite(adj,v,color,colorOfV) == false)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V,-1);
        
        //1-red
        //0- green
        
        vector<int> adj[V];
        
        for(auto &e :  edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(color[i] == -1)
                if(checkBipartite(adj, i, color, 1) == false)
                    return false;
        }
        
        return true;
    }
};