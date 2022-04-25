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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* vhead = new ListNode(0, head);
        ListNode* vpre = vhead;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            vpre = vpre->next;
        }
        vpre->next = nullptr;
        ListNode* cur = slow;
        ListNode* pre = nullptr;
        ListNode* temp = nullptr;
        while(slow != nullptr) {
            temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        while(head != nullptr) {
            if(head->val != pre->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};