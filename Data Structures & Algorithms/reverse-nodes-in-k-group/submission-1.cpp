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
    ListNode* orig = NULL;
    void rev(ListNode *head , ListNode *prev , int rem){
        if(rem == 0)return;         
        rev(head->next , head , rem - 1);        
        head->next = prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *first , *last , *prevTail = NULL;
        int rem = 0;
        for(int i = 0 ; head != NULL; i++){
            ListNode *nxt = head->next;
            if(i % k == 0){
                first = head;
                rem = 1;
            }
            if(i % k == (k - 1)){
                rem = 0;
                last = head;
                rev(first , NULL , k);                
                if (prevTail) prevTail->next = last; 
                prevTail = first;
                if(orig == NULL){
                    orig = last;
                }
                
            }
            head = nxt;
        }
        if(rem)prevTail->next = first;
        return orig;
    }
};
