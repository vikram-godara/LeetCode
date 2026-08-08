class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto x : roads) {
            int u = x[0];
            int v = x[1];
            int d = x[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;

        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto x : adj[node]) {
                int next = x.first;
                int dist = x.second;

                ans = min(ans, dist);

                if (!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }

        return ans;
    }
};