class Solution {
public:
    int MOD  = 1e9 + 7;
    int solve(int steps, int new_len , int ind , vector<vector<int>>&dp){
        if(ind < 0 || ind >= new_len) return 0;
        if(steps == 0){
            return ind==0;
        }
        if(dp[ind][steps]!=-1) return dp[ind][steps];
        int stay = solve(steps-1,new_len,ind,dp);
        int right = solve(steps-1,new_len,ind+1,dp);
        int left = solve(steps-1,new_len,ind-1,dp);
        return dp[ind][steps] = ((long long)stay + right + left) % MOD;
    }
    int numWays(int steps, int arrLen) {
        int new_len = min(arrLen,steps/2+1);
        cout<<new_len;
        vector<vector<int>>dp(new_len+1,vector<int>(steps+1,-1));
        return solve(steps,new_len,0,dp);
    }
};