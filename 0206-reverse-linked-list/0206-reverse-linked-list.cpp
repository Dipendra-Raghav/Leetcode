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
   ListNode* ans=NULL;
    ListNode* solve(ListNode* node)
    {
        if(node==NULL || node->next==NULL)
        {
            ans=node;
            return node;
        }
        ListNode* temp=solve(node->next);
        temp->next=node;
        node->next = NULL;
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* node=solve(head);
        
        return ans;
        
    }
};