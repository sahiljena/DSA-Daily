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
    ListNode* middleNode(ListNode* head) {
        int len = 1;
        ListNode* tempHead = head;
        while(tempHead){
            len++;
            tempHead=tempHead->next;
        }
        tempHead=head;
        int mid = len/2;
        while(tempHead){
            --len;
            if(len==mid){
                head=tempHead;
                break;
            }
            tempHead=tempHead->next;
        }
        return head;
    }
};