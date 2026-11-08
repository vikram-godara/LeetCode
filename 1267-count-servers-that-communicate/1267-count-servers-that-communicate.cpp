class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vector<int>row(m,0) , column(n,0);
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    column[j]++;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    if(row[i] >1 || column[j]>1)ans++;
                }
            }
        }
        return ans;

    }
};