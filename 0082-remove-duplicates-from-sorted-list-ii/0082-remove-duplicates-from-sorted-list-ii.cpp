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
    void delNode(ListNode*&head, ListNode* node){
        ListNode* temp = head;
        if(temp==node){
            head=head->next;
            return;
        }
        if(node->next==nullptr){
            while(temp){
                if(temp->next->next==nullptr){
                    temp->next=nullptr;
                    return;
                }
                temp=temp->next;
            }
        }
        while(temp->next){
            if(temp->next==node){
                temp->next=temp->next->next;
                return;
            }
            temp=temp->next;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* temp = head;
        map<int,int>todel;
        while(temp){
            todel[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(todel[temp->val]>1){
                delNode(head,temp);
            }
            temp=temp->next;
        }
        return head;
    }
};