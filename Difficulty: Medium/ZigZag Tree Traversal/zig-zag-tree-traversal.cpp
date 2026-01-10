/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        if(root==NULL)
            return {};
            
        vector<int> result;
        
        queue<Node*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while(!q.empty()){
            
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);
            
            for(int i=0;i<levelSize;i++){
                
                Node* node = q.front();
                q.pop();
                
                int index = leftToRight ? i : (levelSize - i - 1);
                currentLevel[index] = node->data;
                
                if(node->left != NULL)
                    q.push(node->left);
                    
                if(node->right != NULL)
                    q.push(node->right);
                
            }
            
            leftToRight = !leftToRight;
            
            for(int val: currentLevel)
                result.push_back(val);
        }
        return result;
    }
};