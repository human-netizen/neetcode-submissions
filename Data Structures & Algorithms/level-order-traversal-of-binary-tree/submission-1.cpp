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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>old;        
        old.push(root);
        vector<vector<int> > ans;
        vector<int>oldi;
        while(!old.empty()){
            oldi.clear();
            int sz = old.size();
            for(int i = 0 ; i < sz ; i++)
            {
                auto v = old.front();
                old.pop();
                if(v == NULL)continue;
                oldi.push_back(v->val);
                old.push(v->left);
                old.push(v->right);
            }
            
            if(!oldi.empty())ans.push_back(oldi);
            
        }
        return ans;

    }
};
