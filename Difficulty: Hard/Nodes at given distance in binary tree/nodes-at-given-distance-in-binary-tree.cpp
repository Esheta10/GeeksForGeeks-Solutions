/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {

  public:
    unordered_map<Node*,Node*> parent;
    
    void addParent(Node* root){
        
        if(root == NULL)
            return;
        
        if(root->left != NULL)
            parent[root->left] = root;
        addParent(root->left);
        
        if(root->right != NULL)
            parent[root->right] = root;
        addParent(root->right);
    }
    void collectKNodes(Node* target, int k, vector<int>& result){
        
        queue<Node*> que;
        que.push(target);
        
        unordered_set<int> visited;
        visited.insert(target->data);
        
        while(!que.empty()){
            
            int n = que.size();
            
            if(k==0)
                break;
                
                while(n--){
                    
                    Node* node = que.front();
                    que.pop();
                    
                    //1. left child
                    if(node->left != NULL && visited.find(node->left->data) == visited.end()){
                        que.push(node->left);
                        visited.insert(node->left->data);
                    }
                    
                    //2. right child
                    if(node->right != NULL && visited.find(node->right->data) == visited.end()){
                        que.push(node->right);
                        visited.insert(node->right->data);
                    }
                    //3. parent(upar) ki taraf
                    if(parent.find(node) != parent.end() &&  visited.find(parent[node]->data) == visited.end()){
                        
                        que.push(parent[node]);
                        visited.insert(parent[node]->data);
                    }
                }
                k--;
        }
        while(!que.empty()){
            Node* temp = que.front();
            que.pop();
            
            result.push_back(temp->data);
        }
    }
    Node* findTarget(Node* root,int target){
        
        if(root == NULL)
            return NULL;
            
        if(root->data == target)
            return root;
        
        Node* left = findTarget(root->left,target);
        if(left != NULL)
            return left;
        
        return findTarget(root->right,target);
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        vector<int> result;
        
        addParent(root);
        
        Node* targetNode = findTarget(root,target);
        collectKNodes(targetNode,k, result);
        
        sort(result.begin(),result.end());
        return result;
    }
};