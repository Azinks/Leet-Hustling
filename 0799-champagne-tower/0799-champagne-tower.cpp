class Solution {
public:
    double solve(int poured, int i, int j,vector<vector<double>>&dp){
        if(i < 0 || j < 0 || i < j){
            return 0.0;
        }
        if(dp[i][j]!=-1.0) return dp[i][j];
        if(i == 0 && j == 0) return poured;
        double upright = (solve(poured , i - 1 , j - 1 , dp) - 1)/2.0;
        double upleft = (solve(poured , i - 1 , j , dp) - 1)/2.0;
        if(upright < 0) upright = 0.0;
        if(upleft < 0) upleft = 0.0;
        return dp[i][j] = upright + upleft;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(query_row + 1 , vector<double>(query_glass + 1 , -1.0));
        return min(1.0,solve(poured , query_row , query_glass , dp));
    }
};