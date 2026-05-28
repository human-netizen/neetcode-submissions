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
    TreeNode* rootFinder(TreeNode *root , TreeNode* subRoot){

        if(root == NULL)return NULL;
        if(root->val == subRoot->val)return root;
        TreeNode *left = rootFinder(root->left , subRoot);
        TreeNode *right = rootFinder(root->right , subRoot);
        if(left == NULL)return right;
        return left;

    }
    bool isSub(TreeNode* temp ,TreeNode* subRoot){
        if(subRoot == NULL && temp == NULL)return 1;
        if(temp == NULL && subRoot != NULL)return 0;
        if(temp != NULL && subRoot == NULL)return 0;
        if(temp->val != subRoot->val)return 0;
        int lefti = isSub(temp->left , subRoot->left);
        int righti = isSub(temp->right , subRoot->right);
        return (lefti + righti == 2);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* temp = rootFinder(root , subRoot);
        return isSub(temp , subRoot);
        
    }
};
