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

        int heightP = 0;
        int heightQ = 0;
        int cur = 1;
        while(tempP != p){
            cur*=2;
            if(tempP->val >= p->val){
                tempP = tempP->left;
            }
            else{
                tempP = tempP->right;
                cur++;
            }

            heightP++;
        }
        int pNode = cur;
        cur = 1;
        while(tempQ != q){

            cur*=2;
            if(tempQ->val >= q->val){                
                tempQ = tempQ->left;
            }
            else{
                tempQ = tempQ->right;
                cur++;
            }
            heightQ++;
        }
        int qNode = cur;
        while(heightP > heightQ){
            heightP--;
            pNode/=2;
        }
        while(heightQ > heightP){
            heightQ--;
            qNode/=2;
        }
        TreeNode* ans = root;
        TreeNode* rr;
        int rVal = 1;
        cout << pNode << " " << qNode << endl;
        auto Finder =  [&](this auto self , int pp , int qq) ->void{
            if(pp == 1){
                rr = root;
                rVal = 1;
                return;
            }
            self(pp / 2 , qq / 2);
            if(rVal*2 == pp){
                rr = rr->left;
                
            }
            else rr = rr->right;
            rVal = pp;
            if(pp == qq){
                ans = rr;            
            }
        };
        Finder(pNode , qNode);
        return ans;

    }
};
