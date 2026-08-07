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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* ne = new ListNode();
        ListNode* head = ne;
        ListNode* prev = head;
        while(l1 || l2){
            int dig1 = 0 , dig2 = 0;
            if(l1 == NULL)dig1 = 0;
            else dig1 = l1->val;
            if(l2 == NULL)dig2 = 0;
            else dig2 = l2->val;
            int sum = dig1 + dig2 + carry;
            ne->val = sum % 10;
            carry = sum / 10;
            ne->next = new ListNode();
            prev = ne;
            ne = ne->next; 
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        } 
        if(carry)ne->val = carry;
        else prev->next = NULL;
        return head;
    }
};
