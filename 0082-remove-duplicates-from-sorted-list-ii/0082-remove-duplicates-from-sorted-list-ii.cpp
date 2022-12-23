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
        if(temp->val==node->val){
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
        int lst = head->val;
        map<int,int>todel;
        while(temp){
            if(temp->next && temp->next->val==lst){
                todel[lst]++;
            }
            temp=temp->next;
            if(temp) lst=temp->val;
        }
        temp=head;
        while(temp){
            if(todel.find(temp->val)!=todel.end()){
                delNode(head,temp);
            }
            temp=temp->next;
        }
        return head;
    }
};