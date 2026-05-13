class Solution {
public:
    void rev(ListNode* head, ListNode* prev, int rem) {
        if (rem <= 1) {
            head->next = prev;
            return;
        }
        ListNode* nxt = head->next;
        head->next = prev;
        rev(nxt, head, rem - 1);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevTail = &dummy;

        while (true) {
            // check if k nodes remain
            ListNode* check = prevTail->next;
            for (int i = 0; i < k; i++) {
                if (!check) return dummy.next;
                check = check->next;
            }

            ListNode* groupStart = prevTail->next;
            ListNode* groupEnd = groupStart;
            for (int i = 1; i < k; i++)
                groupEnd = groupEnd->next;

            ListNode* nxt = groupEnd->next;

            rev(groupStart, NULL, k);

            prevTail->next = groupEnd;
            groupStart->next = nxt;
            prevTail = groupStart;
        }
    }
};