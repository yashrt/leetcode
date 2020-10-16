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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return NULL;
        int nodeNum = 0;
        
        ListNode* temp = head;
        while(temp)
        {
            nodeNum++;
            temp = temp->next;
        }
        if(k % nodeNum == 0)
            return head;
        
        k = k % nodeNum;
        temp = head;
        int count = 0;
        while(count != nodeNum - k - 1)
        {
            count++;
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        count = 0;
        while(count != k - 1)
        {
            count++;
            temp = temp->next;
        }
        
        temp->next = head;
        
        return newHead;
    }
};
