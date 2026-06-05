/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* root;
    int tot = 0;
    void hehe(ListNode* last , ListNode* fast){
        if(last == NULL)return;
        tot++;
        ListNode* nxt = fast;
        if(fast != NULL)nxt = nxt->next;
        if(nxt != NULL)nxt = nxt->next;
        hehe(last->next , nxt);
        if(fast == NULL){
            cout << root->val << " " << last->val << endl;
            ListNode* temp = root->next;
            root->next = last;
            last->next = temp;
            root = temp;
        }
    }
    void reorderList(ListNode* head) {
        root = head;
        hehe(root , root);
        root = head;
        tot--;
        while(tot--){
            root = root->next;
        }
        root->next = NULL;

    }
};
