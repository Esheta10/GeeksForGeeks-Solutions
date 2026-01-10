/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
        if(root == NULL)
            return 0;
            
        queue<Node*> que;
        que.push(root);
        
        int maxSum = root->data;
        // int currentLevel = 1;
        // int resultLevel = 0;
        
        while(!que.empty()){
            
            int n = que.size();
            int sum = 0;
            
            while(n--){
                
                Node* node = que.front();
                que.pop();
                
                sum += node->data;
                
                if(node->left != NULL)
                    que.push(node->left);
                
                if(node->right != NULL)
                    que.push(node->right);
            }
            if(sum > maxSum){
                
                maxSum = sum;
                // resultLevel = currentLevel;
            }
            // currentLevel++;
        }
        return maxSum;
        
    }
};
