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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp)
        {
            temp=temp->next;
            cnt++;
        }
        cnt=cnt-k+1;
        ListNode* chk=head;
        ListNode* first;
        ListNode* last;
        int t=1;
        while(chk)
        {
            if(t==k)first=chk;
            if(t==cnt)last=chk;
            t++;
            chk=chk->next;    
        }
        int flag=first->val;
        first->val=last->val;
        last->val=flag;
        return head;
    }
};