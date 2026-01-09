/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int maxSum;
    int totalSum(Node* root){
        
        if(root == NULL)
            return 0;
        
        int l = totalSum(root->left);
        int r = totalSum(root->right);
        
        int neeche_se_mil_gaya = l + r + root->data;
        int dono_mein_se_koi_ek_acha = max(l,r) + root->data;
        int only_root_acha = root->data;
        
        maxSum = max({maxSum,neeche_se_mil_gaya, dono_mein_se_koi_ek_acha,only_root_acha});
        
        return max(dono_mein_se_koi_ek_acha, only_root_acha);
            
    }
    int findMaxSum(Node *root) {
        // code here
        
        maxSum = INT_MIN;
        
        totalSum(root);
        
        return maxSum;
    }
};