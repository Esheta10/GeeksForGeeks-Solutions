/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool check(Node* l, Node* r){
        if(l== NULL && r==NULL)
            return true;
            
        if(l==NULL || r==NULL)
            return false;
            
        if((l->data == r->data) && check(l->left,r->right) && check(l->right,r->left))
            return true;
            
        return false;
    }
    bool isSymmetric(Node* root) {
        // code here
        if(root == NULL)
            return true;
            
        check(root->left,root->right);
    }
};