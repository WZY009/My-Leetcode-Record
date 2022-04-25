//2022 4.25 16:11 first time to do
//2022 4.25 16:47 pass
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
    ListNode* reverse(ListNode* head, ListNode* end) {
        if(head == end) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* temp;
        while(cur != end) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        cur->next = pre;
        return head;   
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(-501, head);
        ListNode* start = dummyHead; // start points to the lists which will be reversed
        ListNode* end = dummyHead; // end points to the end of reversed lists' end
        ListNode* temp1;
        while(left > 0) {
            if(left == 1) temp1 = start;
            start = start->next;
            left--;
        }
        while(right-- > 0) {
            end = end->next;
        }
        ListNode* nextNode = end->next;
        ListNode* temp2 = reverse(start, end);
        temp1->next = end;
        temp2->next = nextNode;
        return dummyHead->next;
    }
};