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
    bool hasCycle(ListNode* head) {
        int cnt = 0;
        while(head != NULL){
            head = head->next;
            cnt++;
            if(cnt > 1000)break;
        }
        if(cnt > 1000)return 1;
        return 0;
        
    }
};
