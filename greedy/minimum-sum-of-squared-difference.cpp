
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> arr(n);
        long long k = 1LL * k1 + k2;
        long long sum = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            arr[i] = abs(nums1[i] - nums2[i]);
            sum += arr[i];
            mx = max(mx, arr[i]);
        }

        if (sum <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int x : arr) {
                need += max(0, x - mid);
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        for (int i = 0; i < n; i++) {
            k -= max(0, arr[i] - low);
            arr[i] = min(arr[i], low);
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (arr[i] == low) {
                arr[i]--;
                k--;
            }
        }

        long long ans = 0;

        for (int x : arr) {
            ans += 1LL * x * x;
        }

        return ans;
    }
};
