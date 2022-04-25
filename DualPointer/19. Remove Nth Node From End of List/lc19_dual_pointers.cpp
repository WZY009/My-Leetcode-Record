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
        ListNode* virtualHead = new ListNode(0, head);
        ListNode* slow = virtualHead;
        ListNode* fast = virtualHead;
        while (n-- > 0) // go for n steps
            fast = fast->next;
        fast = fast->next; // go for another step
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return virtualHead->next;
    }
};
