// 2022 4.25 15:56 Method1: recursion
// 2022 4.25 16:02 pass
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
    ListNode* reverse(ListNode* pre, ListNode* head) {
        if(head == nullptr) return pre;
        ListNode* temp = head->next;
        head->next = pre;
        pre = head;
        return reverse(pre, temp);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        return reverse(nullptr, head);
    }
};