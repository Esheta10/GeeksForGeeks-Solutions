class Solution {
  public:
    bool topologicalSort(unordered_map<int,vector<int>>& adj, int N, vector<int>& indegree){
        
        queue<int> que;
        int count=0;
        
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
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
                }
            }
        }
        
        if(count==N)// visited all coureses, no cycle
            return true;
            
        return false;
    }
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        
        unordered_map<int,vector<int>> adj;
        
        vector<int> indegree(N,0); // Kahn's Algorithm
        
        for(auto &vec : prerequisites){
            
            int a = vec.first;
            int b = vec.second;
            
            // b--->a
            adj[b].push_back(a);
            
            // arrow---> a ki taraf aa raha
            indegree[a]++;
        }
        
        return topologicalSort(adj, N, indegree);
    }
};