class Solution {
  public:
    bool isCompleteBT(Node* root) {
        // code here
        
        queue<Node*> q;
        q.push(root);
        
        bool past = false; // kya humne NULL node pehle dekha hai?
        while(q.empty()==false){
            
            Node*node = q.front();
            q.pop();
            
            if(node == NULL){
                past = true;
            } else {
                if(past == true)
                    return false;
                    
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};