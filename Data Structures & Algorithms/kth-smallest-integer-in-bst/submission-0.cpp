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
    vector<int>childCnt = vector<int>(2005);
    int childer(TreeNode* root , int i){
        if(root == NULL)return 0;
        if(childCnt[i] != 0)return childCnt[i];
        childCnt[i] = 1 + childer(root->left , 2 * i) + childer(root->right , 2 * i + 1);
        cout << root->val << ": " << childCnt[i] << endl;
        return childCnt[i];
    }
    int smol(TreeNode* root , int k , int up , int i){
        if(root == NULL)return 0;
        cout << root->val << " " << up << " " << childer(root->left , 2 * i) << endl;
        if(up + childer(root->left , 2 * i) + 1 == k)return root->val;
        if(up + childer(root->left , 2 * i) < k)return smol(root->right , k , 1 + up + childer(root->left , 2 * i) , 2 * i + 1);
        return smol(root->left , k , up , 2 * i);
    }
    int kthSmallest(TreeNode* root, int k) {
        return smol(root , k , 0 , 1);
    }
    
};
