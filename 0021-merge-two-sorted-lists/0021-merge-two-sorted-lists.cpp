class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head=NULL;
        ListNode* prev=NULL;
        
        if(list1==NULL && list2!=NULL)return list2;
        else if(list2==NULL && list1!=NULL)return list1;
        else if(list1==NULL && list2==NULL) return head;
        else if(list1->val<=list2->val)
        {
            head=list1;
            prev=list1;
            list1=list1->next;
        }
        else
        {
            head=list2;
            prev=list2;
            list2=list2->next;
        }
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                prev->next=list1;
                prev=list1;
                list1=list1->next;
            }
            else
            {
                prev->next=list2;
                prev=list2;
                list2=list2->next;
            }
        }
        
        while(list1!=NULL)
        {
                prev->next=list1;
                prev=list1;
                list1=list1->next;
        }
        while(list2!=NULL)
        {
                prev->next=list2;
                prev=list2;
                list2=list2->next;
        }
        prev->next=NULL;
        
        return head;
        
    }
};