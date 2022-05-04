// 2022 5.4 19:57
// 2022 5.4 19:59 (1) My edition
// 2022 5.4 20:59 (2)
// 2022 5.4 21:03 (2) - without review
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
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* cur = head;
        int i = 0;
        int res;
        while(cur != nullptr) {
            i++;
            if(0 == rand() % i) {
                res = cur->val;
            }
            cur = cur->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */