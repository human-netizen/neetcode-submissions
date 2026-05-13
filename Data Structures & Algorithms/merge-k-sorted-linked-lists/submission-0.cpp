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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head , *list = new ListNode();
        int k = lists.size();
        head = list;

        while(1){
            ListNode *temp1 = new ListNode(INT_MAX);        
            ListNode** temp = &temp1;
            int done = 0;        
            for(int i = 0 ; i < k; i++){
                //cout << lists[i]->val << " " ;
                if(lists[i] == NULL){
                    done++;
                    continue;
                }
                if((*temp)->val > lists[i]->val)temp = &lists[i];
            }

            
            if(done == k){
                break;            
            }
            ListNode* ne = new ListNode();
            list->next = ne;
            list = list->next;
            list->val = (*temp)->val;
            *temp = (*temp)->next;      
            
        }
        return head->next;
    }
};
