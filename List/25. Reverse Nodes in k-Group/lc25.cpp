//2022 4.25 16:50 ~ 16:59 想不出什么好解法！
// This quesiton is a little bit tricky. You have to know b is not inculded in the list reversion or you will feel extremely painful when you writing the code!
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
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        ListNode* temp;
        ListNode* cur1 = a;   
        while(cur1 != b) {
            temp = cur1->next;
            cur1->next = pre;
            pre = cur1;
            cur1 = temp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* cur1 = head;
        ListNode* cur2 = head;
        for (int i = 0; i < k; i++) {
            if(cur2 == nullptr) return head; // It reresent k is larger than the number of node!
            cur2 = cur2->next;
        }
        ListNode* newHead = reverse(cur1, cur2); // Pay attention, the reversing list doesn't include *b
        cur1->next = reverseKGroup(cur2, k);
        return newHead;
    }
};