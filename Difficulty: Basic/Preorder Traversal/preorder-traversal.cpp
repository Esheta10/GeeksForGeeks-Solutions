/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void preorder(Node* root, vector<int>& result){
        
        if(root == NULL)
            return;
            
        result.push_back(root->data);
        preorder(root->left, result);
        preorder(root->right,result);
        
    }
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> result;
        
        preorder(root,result);
        
        return result;
    }
};