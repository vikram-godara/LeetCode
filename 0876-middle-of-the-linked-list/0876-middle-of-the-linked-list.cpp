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
        int totalnodes = 0;
        ListNode*temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            totalnodes++;
        }
        int middle = (totalnodes+2)/2;
        temp = head;
        int cnt=0;
        while(temp!=nullptr){
            if(cnt == middle-1){
                return temp;
            }
            cnt++;
            temp = temp->next;
        }
        return temp;

    }
};