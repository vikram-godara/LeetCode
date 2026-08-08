class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int count = 0;
        int i = 0;
        while (i < n) {
            int maxWeight = weight[i];
            int j = i;
            while (j < n) {
                maxWeight = max(maxWeight, weight[j]);

                if (weight[j] < maxWeight) {
                    count++;
                    i = j + 1;
                    break;
                }
                j++;
            }
            if (j == n)
                break;
        }
        return count;
    }
};