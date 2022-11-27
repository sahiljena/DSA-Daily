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
    ListNode* reverseList(ListNode *head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;
        while(curr != NULL){
           Next = curr -> next;
           curr -> next = prev;
           prev = curr;
           curr = Next;
        }
        return prev;
    }
    ListNode* helper(ListNode *head) {
        ListNode *revHead = reverseList(head);
        head = revHead;
        int maxfar = INT_MIN;
        ListNode *prev = revHead;
        while(revHead != NULL){ 
            int data = revHead -> val;
            if(data >= maxfar){
               prev = revHead;
               revHead = revHead -> next;
               maxfar = data; 
            }
            else {
                ListNode *temp = revHead;
                prev->next = revHead -> next;
                revHead = revHead -> next;
                delete temp;
            }
        }
        return reverseList(head);
    }

    ListNode* removeNodes(ListNode* head) {
        head = helper(head); 
        return head;
    }
};