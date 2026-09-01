class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int, int>> litter;
        int sr, sc;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0) return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        int fullMask = (1 << k) - 1;

        auto encode = [&](int r, int c, int mask, int e) {
            return (((mask * m + r) * n + c) * (energy + 1) + e);
        };

        int totalStates = (1 << k) * m * n * (energy + 1);
        vector<bool> visited(totalStates, false);

        queue<int> q;

        int start = encode(sr, sc, 0, energy);
        visited[start] = true;
        q.push(start);

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int state = q.front();
                q.pop();

                int e = state % (energy + 1);
                state /= (energy + 1);

                int c = state % n;
                state /= n;

                int r = state % m;
                int mask = state / m;

                if (mask == fullMask)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int nextState = encode(nr, nc, nmask, ne);

                    if (!visited[nextState]) {
                        visited[nextState] = true;
                        q.push(nextState);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};