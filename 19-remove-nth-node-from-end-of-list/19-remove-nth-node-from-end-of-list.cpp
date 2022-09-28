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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //if(!head->next && n==1) return NULL;
        vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp){
            vec.push_back(temp);
            temp=temp->next;
        }
        int vn = vec.size();
        if(vn==n){
            head=head->next;
            return head;
        }
        temp = vec[vn-n];
        ListNode* tempPrev = vec[vn-n-1];
        tempPrev->next = temp->next;
        return head;
    }
};