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
    
    void findMaxDiff(Node* root, int minV, int maxV) {
        if(!root)
            return;
        
        // Calculate difference: ancestor - current (descendant)
        // We want max difference, so check both max and min ancestors
        result = max(result, maxV - root->data);  // max ancestor - current
        result = max(result, minV - root->data);  // min ancestor - current
        
        // Update min and max for children (current node becomes ancestor)
        minV = min(root->data, minV);
        maxV = max(root->data, maxV);
        
        findMaxDiff(root->left, minV, maxV);
        findMaxDiff(root->right, minV, maxV);
    }
    
    int maxDiff(Node* root) {
        // code here
        result = INT_MIN;
        
        // Start from root's children (root is the first ancestor)
        if(root->left) 
            findMaxDiff(root->left, root->data, root->data);
        if(root->right) 
            findMaxDiff(root->right, root->data, root->data);
            
        return result;
    }
};