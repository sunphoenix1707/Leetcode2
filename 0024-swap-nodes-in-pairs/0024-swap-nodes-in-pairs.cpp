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
    ListNode* swapPairs(ListNode* head) {
        ListNode* reverseHead=NULL;
       ListNode* tail=head;
        if(head==NULL)  return NULL;
        int count=0;
        while(head!=NULL && count<2)  {
            ListNode* temp=head;
            head=head->next;
            temp->next=reverseHead;
            reverseHead=temp;
            count++;
        }
        tail->next = swapPairs(head);
        return reverseHead;
    }
};