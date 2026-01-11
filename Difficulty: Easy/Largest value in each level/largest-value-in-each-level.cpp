// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        if(root==NULL)
            return {};
            
        queue<Node*> que;
        que.push(root);
        
        vector<int> result;
        
        while(!que.empty()){
            
            int n = que.size();
            int max_element = INT_MIN;
            
            while(n--){
                
                Node* node = que.front();
                que.pop();
                
                max_element = max(max_element, node->data);
                
                if(node->left != NULL)
                    que.push(node->left);
                    
                if(node->right != NULL)
                    que.push(node->right);
            }
            result.push_back(max_element);
        }
        return result;
    }
};