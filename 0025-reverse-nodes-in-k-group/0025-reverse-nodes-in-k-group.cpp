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
 //
class Solution {

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* tail=head;
         ListNode* reverseNode=NULL;
        int count=0;
        // Check if there are at least k nodes remaining
    ListNode* checkNode = head;
    for (int i = 0; i < k; ++i) {
        if (checkNode == NULL) {
            // If there are less than k nodes remaining, return head
            return head;
        }
        checkNode = checkNode->next;
    }
        while(head!=NULL && count<k)  {
              ListNode* temp=head;
              head=head->next;
              temp->next = reverseNode;
              reverseNode=temp;
               count++;
        }
        
        tail->next =  reverseKGroup(head,k);
        return reverseNode;
    }
};