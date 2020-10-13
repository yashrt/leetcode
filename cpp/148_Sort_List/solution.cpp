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
    ListNode* sortList(ListNode* head) {
        vector<pair<int, ListNode*>> temp;
        
        if(!head)
            return NULL;
        
        while(head)
        {
            temp.push_back(make_pair(head->val, head));
            head = head->next;
        }
        
        sort(temp.begin(), temp.end());
        head = temp[0].second;
        ListNode* ptr;
        for(int i=0; i<temp.size()-1; i++)
        {
            ptr = temp[i].second;
            ptr->next = temp[i+1].second;
        }
        ptr->next->next = NULL;
        return head;
    }
};
