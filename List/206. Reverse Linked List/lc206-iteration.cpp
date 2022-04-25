// 2022 4.25 16:03 Method2: iteration
// 2022 4.25 16:06 pass
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre = nullptr;
        ListNode* temp;
        while(head != nullptr) {
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};