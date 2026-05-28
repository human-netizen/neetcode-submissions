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
    
    bool isSub(TreeNode* temp ,TreeNode* subRoot){
        if(subRoot == NULL && temp == NULL)return 1;
        if(temp == NULL && subRoot != NULL)return 0;
        if(temp != NULL && subRoot == NULL)return 0;
        if(temp->val != subRoot->val)return 0;
        bool lefti = isSub(temp->left , subRoot->left);
        bool righti = isSub(temp->right , subRoot->right);
        return (righti && lefti);
    }
    bool parbe(TreeNode *root , TreeNode* subRoot){
        if(isSub(root , subRoot))return 1;
        bool one = isSub(root->left , subRoot);
        bool two = isSub(root->right , subRoot);
        return (one | two);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return parbe(root , subRoot);
        
    }
};
