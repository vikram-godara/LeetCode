class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), sz(n, 1);
        vector<int> val(n), pref(n), order;

        for (int i = 0; i < n; i++)
            val[i] = 1 << (s[i] - 'a');

        // Build parent, depth and traversal order
        vector<int> st = {0};
        vector<int> parent(n, -1);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            tin[u] = order.size();
            order.push_back(u);

            for (int v : adj[u]) {
                if (parent[v] != -1) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int i = 0; i < n; i++) {
            int u = order[i];
            up[0][u] = parent[u];
            pref[u] = (u == 0 ? val[u] : pref[parent[u]]);
            if (u != 0) pref[u] ^= val[u];
        }

        for (int i = n - 1; i > 0; i--)
            sz[parent[order[i]]] += sz[order[i]];

        for (int u = 0; u < n; u++)
            tout[u] = tin[u] + sz[u] - 1;

        for (int j = 1; j < LOG; j++)
            for (int u = 0; u < n; u++)
                up[j][u] = up[j-1][up[j-1][u]];

        // Fenwick tree for subtree range XOR updates
        vector<int> bit(n + 2, 0);

        auto add = [&](int i, int x) {
            for (; i <= n + 1; i += i & -i)
                bit[i] ^= x;
        };

        auto get = [&](int i) {
            int ans = 0;
            for (; i > 0; i -= i & -i)
                ans ^= bit[i];
            return ans;
        };

        auto update = [&](int u, int delta) {
            add(tin[u] + 1, delta);
            add(tout[u] + 2, delta);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int d = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++)
                if (d & (1 << j)) u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string &q : queries) {
            string op;
            int u, v;
            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int nw = 1 << (c - 'a');
                int delta = val[u] ^ nw;

                update(u, delta);
                val[u] = nw;
            } else {
                ss >> v;

                int w = lca(u, v);
                int pu = pref[u] ^ get(tin[u] + 1);
                int pv = pref[v] ^ get(tin[v] + 1);

                int mask = pu ^ pv ^ val[w];
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};