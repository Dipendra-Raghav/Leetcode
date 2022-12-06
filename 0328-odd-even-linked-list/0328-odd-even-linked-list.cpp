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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* even=head->next;
        ListNode* temp=head->next;
        ListNode* odd=head;
        while(odd->next!=NULL && odd->next->next!=NULL)
        {
            odd->next=odd->next->next;
            odd=odd->next;
            if(even->next != NULL && even->next->next != NULL)
            {
                even->next=even->next->next;
                even=even->next;
            }
            
        }
        odd->next=temp;
        even->next=NULL;
        return head;
        
    }
};