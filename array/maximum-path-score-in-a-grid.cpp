class Solution {
public:
    int m;
    int n;
    int solve(vector<vector<int>>& grid,int k,int i,int j,int cost,vector<vector<vector<int>>>&t){
        if(i>=m || j>=n)
           return INT_MIN;
        int newcost = cost + (grid[i][j]>0 );

        if(newcost>k)
           return INT_MIN;
        
        if(i==m-1 && j == n-1) 
          return grid[i][j];
        if(t[i][j][cost]!=-1){
            return t[i][j][cost];
        }
        //down
        //right
        int down = solve(grid,k,i+1,j,newcost,t);
        int right = solve(grid,k,i,j+1,newcost,t);

        int bestnext = max(down,right);

        if(bestnext == INT_MIN){
            return t[i][j][cost] = INT_MIN;
        }

        return t[i][j][cost] = grid[i][j]+ bestnext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>>t(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int result = solve(grid,k,0,0,0,t);
        return (result == INT_MIN ? -1 : result);
        
    }
};