class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            vector<int> prefUp(m + 1, 0);
            vector<int> prefDown(m + 1, 0);

            for (int i = 1; i <= m; i++) {
                prefUp[i] = prefUp[i - 1] + up[i];
                if (prefUp[i] >= MOD) prefUp[i] -= MOD;

                prefDown[i] = prefDown[i - 1] + down[i];
                if (prefDown[i] >= MOD) prefDown[i] -= MOD;
            }

            vector<int> nup(m + 1), ndown(m + 1);

            int totalUp = prefUp[m];

            for (int v = 1; v <= m; v++) {
                nup[v] = prefDown[v - 1];

                ndown[v] = totalUp - prefUp[v];
                if (ndown[v] < 0) ndown[v] += MOD;
            }

            up.swap(nup);
            down.swap(ndown);
        }

        long long ans = 0;

        if (n == 2) {
            for (int v = 1; v <= m; v++) {
                ans += up[v];
                ans += down[v];
            }
        } else {
            for (int v = 1; v <= m; v++) {
                ans += up[v];
                ans += down[v];
            }
        }

        return ans % MOD;
    }
};