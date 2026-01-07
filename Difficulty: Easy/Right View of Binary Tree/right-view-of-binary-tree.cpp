/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        if(root == NULL)
            return {};
            
        queue<Node*> q;
        q.push(root);
        
        vector<int> result;
        
        while(q.empty() == false){
            
            int n = q.size();
            Node* node = NULL;
            
            while(n--){
                
                node = q.front();
                q.pop();
                
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            result.push_back(node->data);
        }
        return result;
    }
};