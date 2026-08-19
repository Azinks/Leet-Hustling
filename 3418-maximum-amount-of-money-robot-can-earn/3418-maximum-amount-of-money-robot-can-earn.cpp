class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& coins , int n ,int m , int neu ,vector<vector<vector<int>>>&dp){
        if(i == n-1 && j == m-1){
            if(coins[i][j] < 0 && neu > 0) return 0;
            return coins[i][j];
        }
        if(dp[i][j][neu]!=-1) return dp[i][j][neu];
        if(i >= n || j >= m) return INT_MIN;
        int take = coins[i][j] + max(solve(i+1,j,coins,n,m,neu,dp),solve(i,j+1,coins,n,m,neu,dp));
        int not_take = INT_MIN;
        if(coins[i][j] < 0 && neu > 0){
            int skipdown = 0 + solve(i+1,j,coins,n,m,neu-1,dp);
            int skipup = 0 + solve(i,j+1,coins,n,m,neu-1,dp);
            not_take = max(skipdown,skipup);
        }
        return dp[i][j][neu] = max(take,not_take);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(3,-1)));
        return solve(0,0,coins,n,m,2,dp);
    }
};