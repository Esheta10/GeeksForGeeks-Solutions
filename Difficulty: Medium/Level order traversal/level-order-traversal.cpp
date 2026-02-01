/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        if(root == NULL)
            return {};
        vector<vector<int>> result;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for(int i=0; i<levelSize; i++){
                
                Node* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->data);
                
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};