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
    ListNode* findmiddle(ListNode* head)  {
         ListNode* slow=head;
        ListNode* fast=slow;
        while(fast->next!=NULL && fast->next->next!=NULL)  {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode* head)  {
        ListNode* reversehead=NULL;
        while(head!=NULL)   {
            ListNode* temp=head;
            head=head->next;
            temp->next=reversehead;
            reversehead=temp;
        }
        return reversehead;
    }
void reorderList(ListNode* head) {
     if (!head || !head->next || !head->next->next) return;
       ListNode* mid = findmiddle(head);
    ListNode* right = reverse(mid->next);
    mid->next = NULL;
    ListNode* left = head;
    
    while(right)  
    {
        ListNode* temp1=left->next;
        left->next=right;
        ListNode* temp2=right->next;
        right->next=temp1;
        left=temp1;
        right=temp2;
        
        
    }
    

}



};