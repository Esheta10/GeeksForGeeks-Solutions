class Solution {
  public:
    vector<int> topologicalSort(unordered_map<int,vector<int>>& adj, int n, vector<int>& indegree){
        
        queue<int> que;
        int count = 0;
        
        vector<int> result;
        
        for(int i=0;i<n;i++){
            
            if(indegree[i]==0){
                que.push(i);
                count++;
                result.push_back(i);
            }
        }
        
        while(!que.empty()){
            
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]){
                
                indegree[v]--;
                
                if(indegree[v]==0){
                    que.push(v);
                    count++;
                    result.push_back(v);
                }
            }
        }
        
        if(count==n)
            return result;
            
        return {};
    }
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<int> indegree(n,0);
        
        unordered_map<int,vector<int>> adj;
        
        for(auto &vec: prerequisites){
            int u = vec[0];
            int v = vec[1];
            
            // v-->u
            adj[v].push_back(u);
            
            // arrow ---> u ki taraf jaa raha hai
            indegree[u]++;
        }
        
        return topologicalSort(adj, n, indegree);
    }
};