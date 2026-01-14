class Solution {
  public:
    void DFS(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st){
        
        visited[u] = true;
        
        // u bol raha hai, pehle mere baccho(v) ko daalo
        for(int &v: adj[u]){
            
            if(!visited[v]){
                DFS(adj,v,visited,st);
            }
        }
        
        // ab mujhe daalo stack mein
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,false);
        
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(adj,i,visited,st);
            }
        }
        
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};