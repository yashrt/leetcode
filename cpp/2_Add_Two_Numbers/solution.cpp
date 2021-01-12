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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode();
        ListNode* temp = res;
        while (l1 || l2) 
        {
            if (l1 && l2)
            {
                int sum = l1->val + l2->val + carry;
                temp->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1)
            {
                int sum = l1->val + carry;
                temp->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
            }
            else 
            {
                int sum = l2->val + carry;
                temp->val = sum % 10;
                carry = sum / 10;
                l2 = l2->next;
            }
            if (l1 || l2)
            {
                temp->next = new ListNode();
                temp = temp->next;
            } 
            else if (carry)
            {
                temp->next = new ListNode(carry);
            }
        }

        return res;
    }
};
