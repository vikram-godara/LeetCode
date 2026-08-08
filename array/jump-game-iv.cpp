class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        if (n == 1)
            return 0;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        int minstep = 0;
        queue<int> q;
        vector<int> vis(n, 0);
        vis[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {

                int j = q.front();
                q.pop();

                if (j == n - 1)
                    return minstep;

                if (j - 1 >= 0 && !vis[j - 1]) {
                    vis[j - 1] = 1;
                    q.push(j - 1);
                }
                if (j + 1 < n && !vis[j + 1]) {
                    vis[j + 1] = 1;
                    q.push(j + 1);
                }

                for (auto k : mp[arr[j]]) {
                    if (!vis[k]){
                        vis[k] = 1;
                        q.push(k);
                    }
                }
                mp[arr[j]].clear();
            }
            minstep++;
        }
        return -1;
    }
};