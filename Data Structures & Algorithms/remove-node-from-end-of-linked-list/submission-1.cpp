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
        ListNode* prev = head;
        for(int i = 0 ; i < n ; i++){
            prev = temp;
            temp = temp->next;
        }
        if(n == 0)head = head->next;
        else prev->next = temp->next;
        return head;
    }
};
