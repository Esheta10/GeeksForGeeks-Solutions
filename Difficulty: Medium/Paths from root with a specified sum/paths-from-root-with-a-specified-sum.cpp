// User function Template for C++

/*// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};*/

class Solution {
  public:
    vector<vector<int>> result;

    void dfs(Node* root, int currSum, int target, vector<int>& path) {
        if (root == NULL)
            return;

        currSum += root->key;
        path.push_back(root->key);

        // Check at EVERY node (not just leaf)
        if (currSum == target) {
            result.push_back(path);
        }

        dfs(root->left, currSum, target, path);
        dfs(root->right, currSum, target, path);

        path.pop_back(); // backtrack
    }

    vector<vector<int>> printPaths(Node* root, int sum) {
        result.clear();
        vector<int> path;
        dfs(root, 0, sum, path);
        return result;
    }
};

