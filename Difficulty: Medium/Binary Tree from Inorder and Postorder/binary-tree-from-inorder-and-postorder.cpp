/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx){
        
        if(start > end)
            return NULL;
            
        int rootVal = postorder[idx];
        int i = start;
        
        for(; i<=end;i++){
            
            if(inorder[i] == rootVal)
                break;
        }
        idx--;
        
        Node* root = new Node(rootVal);
        root->right = solve(inorder,postorder,i+1,end,idx);
        root->left = solve(inorder,postorder,start,i-1,idx);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n = postorder.size();
        int idx = n-1;
        
        return solve(inorder,postorder,0,n-1,idx);
    }
};