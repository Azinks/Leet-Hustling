class Solution {
public:
    int solve(vector<vector<int>>& grid,int r1,int c1,int r2,int c2,int n,int m,vector<vector<vector<vector<int>>>>&dp){
        if(r1 >= n || r2 >= n || c1 >= m || c2 >= m || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        if(r1 == n - 1 && c1 == m - 1){
            return grid[r1][c1];
        }
        int cherry = 0;
        if(r1 == r2 && c1 == c2){
            cherry += grid[r1][c1];
        }
        else{
            cherry += grid[r1][c1] + grid[r2][c2];
        }
        int d1 = solve(grid , r1 + 1 , c1 , r2 , c2 + 1 , n , m,dp);
        int d2 = solve(grid , r1  , c1 + 1 , r2 + 1, c2  , n , m,dp);
        int d3 = solve(grid , r1 + 1 , c1 , r2 + 1, c2 , n , m,dp);
        int d4 = solve(grid , r1 , c1 + 1, r2 , c2 + 1 , n , m,dp);
        cherry += max(max(d1,d2),max(d3,d4));
        return dp[r1][c1][r2][c2] = cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<vector<int>>>>dp(n+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(n+1,vector<int>(m+1,-1))));
        int res = solve(grid,0,0,0,0,n,m,dp);
        return res < 0 ? 0 : res;
    }
};