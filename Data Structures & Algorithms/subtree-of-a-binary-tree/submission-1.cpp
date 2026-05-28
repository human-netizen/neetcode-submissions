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
        int lefti = isSub(temp->left , subRoot->left);
        int righti = isSub(temp->right , subRoot->right);
        return (lefti + righti == 2);
    }
    bool parbe(TreeNode *root , TreeNode* subRoot){
        if(isSub(root , subRoot))return 1;
        int one = isSub(root->left , subRoot);
        int two = isSub(root->right , subRoot);
        return (one + two) > 0;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return parbe(root , subRoot);
        
    }
};
