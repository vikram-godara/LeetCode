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
        ListNode*temp = head;
        int cnt = 0;
        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }
        if(cnt==n){
            return head->next;
        }
        int r = cnt-n;
        ListNode*temp1 = head;
        int cnt2=1;
        while(temp1!=nullptr){
            if(cnt2 == r){
                temp1->next = temp1->next->next;
                break;
            }
            temp1 = temp1->next;
            cnt2++;
        }
        return head;
    }
};