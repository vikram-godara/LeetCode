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
        int totalnodes = 0;
        ListNode*temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            totalnodes++;
        }
        int neednode = totalnodes-n;
        if(neednode ==0) return head->next;
        int cnt=1;
        temp = head;
        while(temp!=nullptr){
            if(cnt == neednode){
                temp->next = temp->next->next;
                return head;
            }
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
};