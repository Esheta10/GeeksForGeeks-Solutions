/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    int maxWidth(Node* root) {
        // code here
        if(root == NULL)
            return 0;
            
        queue<Node*> que;
        que.push(root);
        
        int maxWidth = 0;
        
        while(!que.empty()){
            
           int levelSize = que.size();
           maxWidth = max(maxWidth, levelSize);
           
           for(int i=0;i<levelSize;i++){
               
             Node* node = que.front();
             que.pop();
             
             if(node->left != NULL)
                que.push(node->left);
            
             if(node->right != NULL)
                que.push(node->right);
             
           }
                
        }
        return maxWidth;
    }
};