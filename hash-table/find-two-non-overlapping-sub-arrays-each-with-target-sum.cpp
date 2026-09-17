class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;

        vector<int> best(n, INT_MAX);
        int sum = 0;
        int ans = INT_MAX;
        int prev = INT_MAX;

        while (j < n) {
            sum += arr[j];

            while (sum > target) {
                sum -= arr[i];
                i++;
            }

            if (sum == target) {
                int l = j - i + 1;
                if (i > 0 && best[i - 1] != INT_MAX) {
                    ans = min(ans, l + best[i - 1]);
                }
                prev = min(l, prev);
            }
            if (j == 0)
                best[j] = prev;
            else {
                best[j] = min(best[j - 1], prev);
            }
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};