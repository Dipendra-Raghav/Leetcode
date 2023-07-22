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
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(head!=NULL)
        {
            curr=head;
            forward=head->next;
            head=head->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
        
        
    }
};