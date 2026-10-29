class Solution {
public:
    int solve(int k, int n , vector<vector<int>>&dp){
        if(k == 1) return n;
        if(n == 0 || n == 1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
        int mn = INT_MAX;
        for(int part = 1 ; part <= n ; part++){
            int tmp = 1 + max(solve(k - 1 , part - 1 , dp),solve(k , n - part , dp));
            mn = min(mn , tmp);
        }
        return dp[k][n] = mn;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(2 + 1,vector<int>(n + 1 , -1));
        return solve(2,n,dp);
    }
};