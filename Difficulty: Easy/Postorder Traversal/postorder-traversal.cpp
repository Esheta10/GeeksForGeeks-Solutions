/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void postorder(Node* root, vector<int>& result){
        if(root == NULL)
            return;
            
        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> result;
        
        postorder(root,result);
        
        return result;
    }
};