class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        while (k--) {

            vector<int> arr;

            // Shift each row to the right
            for (int i = 0; i < m; i++) {

                if (n == 1) {
                    arr.push_back(grid[i][0]);
                    continue;
                }

                int last = grid[i][n - 1];

                for (int j = n - 1; j > 0; j--) {
                    grid[i][j] = grid[i][j - 1];
                }

                arr.push_back(last);
            }

            if (n == 1) {
                for (int i = m - 1; i > 0; i--) {
                    grid[i][0] = arr[i - 1];
                }
                grid[0][0] = arr[m - 1];
            } else {
                for (int i = 1; i < m; i++) {
                    grid[i][0] = arr[i - 1];
                }
                grid[0][0] = arr[m - 1];
            }
        }

        return grid;
    }
};