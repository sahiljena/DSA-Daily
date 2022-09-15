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
    int calcMid(ListNode* head){
        if(head==NULL) return 0;
        return 1+calcMid(head->next);
    }
    void helper(ListNode* head, int mid){
        if(mid-1==0){
            head->next=head->next->next;
            return;
        }
        helper(head->next,mid-1);
    }
    ListNode* deleteMiddle(ListNode* head) {
        int len = calcMid(head); 
        if(len==1) return NULL;
        helper(head,len/2);
        return head;
    }
};