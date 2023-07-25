
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node=head;
        ListNode* temp=head;
        int cnt=0;
        int chk=0;
        
        while(node)
        {
            cnt++;
            node=node->next;
        }
        if(n==cnt)return head->next;
        cnt=cnt-n;
        while(temp)
        {
            chk++;
            if(chk==cnt)
            {
                if(temp->next->next!=NULL)
                temp->next=temp->next->next;
                else
                    temp->next=NULL;
                return head;
            }
           
            temp=temp->next;
        }
        return head;
        
    }
};