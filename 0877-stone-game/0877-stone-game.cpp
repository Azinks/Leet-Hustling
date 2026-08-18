class Solution {
public:
    int solve(vector<int>& piles , int ind , int end , vector<vector<int>>&dp){
        if( ind > end ) return 0;
        if(dp[ind][end]!=-1) return dp[ind][end];
        int take_i = piles[ind] + min(solve(piles,ind+1,end-1,dp),solve(piles,ind+2,end,dp));
        int take_j = piles[end] + min(solve(piles,ind+1,end-1,dp),solve(piles,ind,end-2,dp));
        return dp[ind][end] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int sum = 0;
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i = 0 ; i < piles.size() ; i++){
            sum = sum + piles[i];
        }
        int alice = solve(piles,0 , n - 1,dp);
        if(alice > (sum/2)) return true;
        return false;
    }
};