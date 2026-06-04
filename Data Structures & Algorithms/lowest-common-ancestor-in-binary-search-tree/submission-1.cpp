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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* tempP = root;
        TreeNode* tempQ = root;
        TreeNode* ans = root;
        while(tempP != p && tempQ != q){
            if(p->val <= tempP->val)tempP = temp->left;
            else tempP = tempP->right;
            if(q->val <= tempQ->val)tempQ = tempQ->left;
            else tempQ = tempQ->right;
            if(tempP == tempQ){
                ans = tempP;
            }
            else break;
        }
        return ans;

    }
};
