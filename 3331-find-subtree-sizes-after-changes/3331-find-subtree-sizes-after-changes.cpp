
class Solution {
public:
    vector<vector<int>> adj, newadj;
    vector<int> last, newparent, ans;
    string s;

    void dfs(int node) {
        int ch = s[node] - 'a';
        int old = last[ch];

        if(old != -1)
            newparent[node] = old;
        else
            newparent[node] = node == 0 ? -1 : -1;

        last[ch] = node;

        for(int child : adj[node]) {
            dfs(child);
        }

        last[ch] = old;
    }

    int solve(int node) {
        int cnt = 1;

        for(int child : newadj[node]) {
            cnt += solve(child);
        }

        ans[node] = cnt;
        return cnt;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;

        adj.resize(n);
        newadj.resize(n);
        last.assign(26, -1);
        newparent.assign(n, -1);
        ans.assign(n, 0);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0);

        for(int i = 1; i < n; i++) {
            if(newparent[i] == -1)
                newparent[i] = parent[i];

            newadj[newparent[i]].push_back(i);
        }

        solve(0);

        return ans;
    }
};
