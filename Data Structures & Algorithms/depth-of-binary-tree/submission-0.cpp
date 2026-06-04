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
    int maxDepth(TreeNode* root) {
        int ans;
        auto ansFinder = [&](this auto self , TreeNode* temp , int val) -> void{
            if(temp == NULL)return;
            ans = max(ans , val);
            self(temp->left , val + 1);
            self(temp->right , val + 1);
        };
        ansFinder(root , 1);
        return ans;
    }
};
