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
    int pairSum(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head;
        ListNode* forward=head;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            temp=prev->next;
            curr=forward;   
        }
        
     //   cout<<forward->val<<" "<< prev->val<<" ";
     //    cout<<forward->next->val<<" "<<prev->next->val;
     int mx=0;
     while(forward!=NULL)
     {
         int sum=forward->val+prev->val;
         mx=max(mx,sum);
         forward=forward->next;
         prev=prev->next;
     }
        return mx;
        
    }
};