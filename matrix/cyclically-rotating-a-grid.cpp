class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> v;

            int top = l, left = l;
            int bottom = m - l - 1;
            int right = n - l - 1;

            // top row
            for (int j = left; j <= right; j++)
                v.push_back(grid[top][j]);

            // right col
            for (int i = top + 1; i <= bottom - 1; i++)
                v.push_back(grid[i][right]);

            // bottom row
            for (int j = right; j >= left; j--)
                v.push_back(grid[bottom][j]);

            // left col
            for (int i = bottom - 1; i >= top + 1; i--)
                v.push_back(grid[i][left]);

            int sz = v.size();
            int rot = k % sz;

            vector<int> temp(sz);

            // counter clockwise rotation
            for (int i = 0; i < sz; i++) {
                temp[i] = v[(i + rot) % sz];
            }

            int idx = 0;

            // put back top row
            for (int j = left; j <= right; j++)
                grid[top][j] = temp[idx++];

            // put back right col
            for (int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = temp[idx++];

            // put back bottom row
            for (int j = right; j >= left; j--)
                grid[bottom][j] = temp[idx++];

            // put back left col
            for (int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = temp[idx++];
        }

        return grid;
    }
};