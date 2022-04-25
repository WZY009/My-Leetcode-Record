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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)  return head;
        ListNode* vHead = new ListNode(0, head);
        ListNode* pre = vHead;
        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr) {
            pre->next = temp->next;
            temp->next = temp->next->next;
            pre->next->next = temp;
            temp = temp->next;
            pre = pre->next->next;
        }
        return vHead->next;
    }
};