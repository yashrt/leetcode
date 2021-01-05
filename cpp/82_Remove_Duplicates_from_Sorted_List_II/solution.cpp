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
        if (!head)
            return nullptr;
        ListNode* temp = new ListNode();
        ListNode* res = temp;
        while (head)
        {
            int value = head->val;
            int count = 1;
            head = head->next;
            while(head && head->val == value) {
                count++;
                head = head->next;
            }
            if (count == 1) {
                temp -> next =   new ListNode(value);
                temp = temp -> next;
            }   
        }
        return res->next;
    }
};
