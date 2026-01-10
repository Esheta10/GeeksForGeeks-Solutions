/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
  int rootToLeafSum(Node* root,int curr){
      
      if(root==NULL)
        return 0;
        
        curr = curr*10 + root->data;
        
        if(root->left == NULL && root->right == NULL)
            return curr;
            
        int leftSum = rootToLeafSum(root->left,curr);
        int rightSum = rootToLeafSum(root->right,curr);
        
        return leftSum + rightSum;
            
        
  }
    int treePathsSum(Node *root) {
        // code here.
        
        return rootToLeafSum(root,0);
    }
};