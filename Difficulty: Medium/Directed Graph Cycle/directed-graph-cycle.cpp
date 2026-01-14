class Solution {
  public:
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        
        for(auto &e : edges){
            
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            
        }
        
       vector<int> indegree(V,0);
       
       // 1. fill the indegree
       for(int u=0;u<V;u++){
           
           for(int &v : adj[u])
                indegree[v]++;
       }
       
       // 2. agar indegree==0, fir usko queue mein push karo
       queue<int>que;
       
       int count=0; // count maintain karo , for getting the vertices count
       for(int i=0;i<V;i++){
           if(indegree[i]==0){
               que.push(i);
               count++;
           }
       }
       
       //3. Simple BFS
       
       while(!que.empty()){
           
           int u =  que.front();
           que.pop();
           
           for(int &v : adj[u]){
               
               indegree[v]--;
               
               if(indegree[v] == 0){
                   que.push(v);
                   count++;
               }
           }
       }
       if(count == V)   // count is same as no. of vertices, koi cycle nahi hai
            return false;
            
        return true;
    }
};