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
    int ans;
    void goodFinder(TreeNode* temp , int maxVal){
        if(temp == NULL)return;
        if(temp->val >= maxVal)ans++;
        goodFinder(temp->left , max(maxVal , temp->val));
        goodFinder(temp->right , max(maxVal , temp->val));
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        goodFinder(root , INT_MIN);
        return ans;
    }
};
