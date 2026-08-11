class Solution {
public:
    int solve(int n , int m , vector<vector<int>>& grid , int row , int rob_1 , int rob_2,vector<vector<vector<int>>>&dp){
        if(row >= n || rob_1 < 0 || rob_1 >= m || rob_2 < 0 || rob_2 >= m) return -1e9;
        if(row == n-1){
            if(rob_1 == rob_2) return grid[row][rob_1];
            return grid[row][rob_1] + grid[row][rob_2];
        }
        if(dp[row][rob_1][rob_2]!=-1) return dp[row][rob_1][rob_2];
        int maxi = -1e9;
        for(int i = -1 ; i <= 1 ; i++){
            for(int j = -1 ; j <= 1 ; j++){
                if(rob_1 == rob_2) maxi = max(maxi , grid[row][rob_1]+solve(n,m,grid,row+1,rob_1+i,rob_2+j,dp));
                else maxi = max(maxi , grid[row][rob_1]+grid[row][rob_2]+solve(n,m,grid,row+1,rob_1+i,rob_2+j,dp));
            }
        }
        return dp[row][rob_1][rob_2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return solve(n,m,grid,0,0,m-1,dp);
    }
};