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
        int totalnodes = 0;
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode*temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            totalnodes++;
        }
        int neednode = (totalnodes)/2 +1;
        int cnt=1;
        temp = head;
        while(temp!=nullptr){
            if(cnt == neednode-1){
                temp->next = temp->next->next;
                return head;
            }
            cnt++;
            temp = temp->next;
        }
        return head;
    }
};