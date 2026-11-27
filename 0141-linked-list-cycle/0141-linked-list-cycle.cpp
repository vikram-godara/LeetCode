/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,ListNode*>mp;
        // mp[head] = head->next;
        while(head!=nullptr){
            if(mp.contains(head)){
                return true;
            }
            mp[head] = head->next;
            head = head->next;;
        }
        return false;
    }
};