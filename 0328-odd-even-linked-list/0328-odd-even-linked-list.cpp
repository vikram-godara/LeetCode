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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode*odd = new ListNode(0);
        ListNode*even = new ListNode(0);
        int cnt = 1;
        ListNode*temp = head;
        ListNode*oddt = odd;
        ListNode*event = even;

        while(temp!=nullptr){
            ListNode*newNode = temp->next;
            if(cnt%2){
                oddt->next = temp;
                oddt = oddt->next;
            }
            else{
                event->next = temp;
                event = event->next;
            }
            temp = newNode;
            cnt++;
        }
        event->next = nullptr;
        oddt->next = even->next;
        return odd->next;
        
    }
};