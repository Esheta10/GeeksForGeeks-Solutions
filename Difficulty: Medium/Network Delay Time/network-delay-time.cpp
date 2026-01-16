class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        // code here
        unordered_map<int, vector<pair<int,int>>> adj;
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v,w});
           
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> result(V+1, INT_MAX);
        
        vector<bool> visited(V+1, false);
        
        result[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(visited[node])
                continue;
                
           if(!visited[node])
             visited[node] =  true;
            
            for(auto &neighbor: adj[node]){
                
                int adjNode = neighbor.first;
                int wt = neighbor.second;
                
                if(!visited[adjNode] && d+wt < result[adjNode]){
                    result[adjNode] = d+wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }
        int maxTime = INT_MIN;
        
        for(int i=0;i<V;i++){
            if(result[i] == INT_MAX)
                return -1;
            maxTime = max(maxTime, result[i]);
        }
        return maxTime;
    }
};