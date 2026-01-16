class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        if(edges.size() < V-1)
            return -1;
            
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i=0; i<V; i++){
            parent[i] = i;
        }
        
        int components = V;
        
        for(auto &vec : edges){
            if(find(vec[0]) != find(vec[1])){
                Union(vec[0], vec[1]);
                components--;
            }
        }
        return components-1;
    }
};
