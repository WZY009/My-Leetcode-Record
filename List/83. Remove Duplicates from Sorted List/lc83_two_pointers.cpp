// 2022 4.30 16:00
// 2022 4.30 16:07 一气呵成
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr) {
            if(slow->val == fast->val) {
                if(fast->next == nullptr) slow->next = nullptr;
                fast = fast->next;
            }
            else {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
        }
        return head;
    }
};