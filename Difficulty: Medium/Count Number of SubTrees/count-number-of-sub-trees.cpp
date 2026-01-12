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
    int result;
    int sum(Node* root){
        
        if(root==NULL)
            return 0;
            
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        
        return leftSum + rightSum + root->data;
    }
    void solve(Node* root, int& x){
        
        if(root==NULL)
            return;
            
        int totalSum = sum(root);
        
        if(totalSum == x)
            result++;
            
        solve(root->left,x);
        solve(root->right,x);
    }
    int countSubtrees(Node* root, int x) {
        // code here
        result = 0;
        solve(root,x);
        
        return result;
    }
};