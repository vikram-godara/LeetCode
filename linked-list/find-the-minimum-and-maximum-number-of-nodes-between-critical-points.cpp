class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;
        int maxDistance = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;

            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                if (first == -1) {
                    first = pos;
                } else {
                    minDistance = min(minDistance, pos - prevCritical);
                    maxDistance = max(maxDistance, pos - first);
                }

                prevCritical = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        if (first == -1 || prevCritical == first)
            return {-1, -1};

        return {minDistance, maxDistance};
    }
};