class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X' || board[i][j] == 'S')
                    continue;

                int best = -1;
                long long cnt = 0;

                if (i + 1 < n && score[i + 1][j] != -1) {
                    best = score[i + 1][j];
                }

                if (j + 1 < n && score[i][j + 1] != -1) {
                    best = max(best, score[i][j + 1]);
                }

                if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] != -1) {
                    best = max(best, score[i + 1][j + 1]);
                }

                if (best == -1)
                    continue;

                if (i + 1 < n && score[i + 1][j] == best)
                    cnt += ways[i + 1][j];

                if (j + 1 < n && score[i][j + 1] == best)
                    cnt += ways[i][j + 1];

                if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] == best)
                    cnt += ways[i + 1][j + 1];

                int val = 0;

                if (board[i][j] != 'E')
                    val = board[i][j] - '0';

                score[i][j] = best + val;
                ways[i][j] = cnt % mod;
            }
        }

        if (score[0][0] == -1)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};