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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while(temp){
            temp=temp->next;
            ++c;
        }
        if(c==1) return NULL; 
        int mid = c/2;
        temp=head;
        while(temp){
            if(mid-1==0){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
            --mid;
        }
        return head;
    }
};