class Solution {
public:
    double solve(int n, int k, int row, int col,vector<vector<vector<double>>>&dp){
        if(row < 0 || row >= n || col < 0 || col >= n) return 0;
        if(dp[k][row][col]!=-1) return dp[k][row][col];
        if(k == 0) return 1;
        double res = solve( n,  k-1,  row+2,  col-1,dp)+
                    solve( n,  k-1,  row+1,  col-2,dp)+
                    solve( n,  k-1,  row-2,  col-1,dp)+
                    solve( n,  k-1,  row-1,  col-2,dp)+
                    solve( n,  k-1,  row+2,  col+1,dp)+
                    solve( n,  k-1,  row+1,  col+2,dp)+
                    solve( n,  k-1,  row-2,  col+1,dp)+
                    solve( n,  k-1,  row-1,  col+2,dp);
        return dp[k][row][col] = res/8;
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>>dp(k+1,vector<vector<double>>(n+1,vector<double>(n+1,-1)));
        return solve(n,k,row,col,dp);
    }
};