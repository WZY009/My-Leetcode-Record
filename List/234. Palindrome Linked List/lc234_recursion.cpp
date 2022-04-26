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
    ListNode* left;
    bool reverse(ListNode* right) {
        if(right == nullptr) return true;
        // sitmulate the postorder traversal process
        bool result = reverse(right->next);
        result &= (left->val == right->val);
        left = left->next;
        return result;
    }
    bool isPalindrome(ListNode* head) {
        left = head;
        return reverse(head);
    }
};