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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode();
        cout << n << endl;
        if(n == 0)return root;

        root->val = preorder[0];
        cout << root->val << endl;
        int cur = 1;
        auto dfs = [&](this auto self , int l , int r , int pos , TreeNode* temp) -> void{
            //leftSeg
            if(l > r)return nullptr;
            int val = preorder[cur++];
            TreeNode* hehe = new TreeNode(val);
            root->val = val;
            temp->left =  self(l , pos - 1 , mp[lnode]);
            temp->right = self(pos + 1 , r , mp[rnode])
            return root;
            
        };
        dfs(0 , n - 1 , mp[root->val] , root);
        return root;
        
    }
};
