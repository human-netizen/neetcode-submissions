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
        vector<TreeNode*>old;
        vector<TreeNode*>ne;
        
        old.push_back(root);
        vector<vector<int> > ans;
        vector<int>oldi;
        while(!old.empty()){
            oldi.clear();
            for(auto v : old){
                if(v == NULL)continue;
                oldi.push_back(v->val);
                ne.push_back(v->left);
                ne.push_back(v->right);
            }
            old = ne;
            if(!oldi.empty())ans.push_back(oldi);
            ne.clear();            
        }
        return ans;

    }
};
