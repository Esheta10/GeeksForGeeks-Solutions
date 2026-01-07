/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root == NULL)
            return root;
            
        if(root->data == n1 || root->data == n2)
            return root;
            
        Node* leftN = lca(root->left,n1,n2);
        Node* rightN = lca(root->right,n1,n2);
        
        if(leftN != NULL && rightN != NULL)
            return root;
            
        if(leftN != NULL)
            return leftN;
            
        return rightN;
            
        
    }
};