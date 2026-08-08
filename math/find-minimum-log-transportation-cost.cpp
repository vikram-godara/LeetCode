class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) return 0;

        long long minCost = -1;

        if (n <= k) {
            for (int i = 1; i < m; i++) {
                int a = i;
                int b = m - i;
                if (a <= k && b <= k) {
                    long long cost = (long long)a * b;
                    if (minCost == -1 || cost < minCost) minCost = cost;
                }
            }
        } else if (m <= k) {
            for (int i = 1; i < n; i++) {
                int a = i;
                int b = n - i;
                if (a <= k && b <= k) {
                    long long cost = (long long)a * b;
                    if (minCost == -1 || cost < minCost) minCost = cost;
                }
            }
        } else {
            for (int i = 1; i < n; i++) {
                int a1 = i;
                int b1 = n - i;
                if (a1 <= k && b1 <= k) {
                    for (int j = 1; j < m; j++) {
                        int a2 = j;
                        int b2 = m - j;
                        if (a2 <= k && b2 <= k) {
                            long long cost = (long long)a1 * b1 + (long long)a2 * b2;
                            if (minCost == -1 || cost < minCost) minCost = cost;
                        }
                    }
                }
            }
        }

        return minCost;
    }
};
