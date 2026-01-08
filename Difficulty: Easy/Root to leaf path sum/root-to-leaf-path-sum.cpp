/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool fill(Node* root, int sum, int& target){
        
        if(root == NULL)
            return false;
        
        sum += root->data;
        
        if(root->left==NULL && root->right==NULL){
            if(sum == target)
                return true;
        }
        
        return fill(root->left,sum,target) || fill(root->right,sum,target);
    }
    bool hasPathSum(Node *root, int target) {
        // Your code here
        int sum = 0;
        return fill(root,sum,target);
    }
};