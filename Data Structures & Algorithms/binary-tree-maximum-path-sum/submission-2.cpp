/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sol = INT_MIN;
    int dfs(TreeNode *root){
        int val1 = 0 , val2 = 0;
        if(root->left != NULL)val1 = max(0 , dfs(root->left));
        if(root->right != NULL)val2 = max(0 , dfs(root->right));
        sol = max(sol , val1 + val2 + root->val);
        return root->val + max(val1 , val2);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sol;
    }
};
