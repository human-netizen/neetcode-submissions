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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cur = 0;
        while(temp != NULL) {
            cur++;
            temp = temp->next;
        }
        n = cur - n;
        temp = head;
        for(int i = 0 ; i < n - 1 ; i++){
            temp = temp->next;
        }
        if(temp == head)head = head->next;
        else temp->next = temp->next->next;
        return head;
    }
};
