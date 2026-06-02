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

    int cnt = 0;
    int ans = -1;
    void smol(TreeNode* root , int k){
        if(root == NULL || ans != -1)return;
        
        smol(root->left , k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        smol(root->right , k);
    }
    int kthSmallest(TreeNode* root, int k) {
        smol(root , k);
        return ans;
    }
    
};
