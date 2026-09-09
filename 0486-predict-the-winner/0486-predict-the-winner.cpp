class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int start , int end ,vector<int>& nums,vector<vector<int>>&dp){
        if(start > end) return 0;
        if(start == end) return nums[start];
        if(dp[start][end] != -1) return dp[start][end] % MOD;
        int take_start = nums[start] + min(solve(start + 2 , end , nums,dp),solve(start + 1 , end - 1 , nums,dp));
        int take_end = nums[end] + min(solve(start , end - 2 , nums,dp),solve(start + 1 , end - 1 , nums,dp));
        return dp[start][end] = max(take_start,take_end) % MOD;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = accumulate(begin(nums),end(nums),0);
        vector<vector<int>>dp(n + 1,vector<int>(n + 1,-1));
        int player_1_score = solve(0,n-1,nums,dp);
        int scored_by_player_2 = total_score - player_1_score;
        return player_1_score >= scored_by_player_2;
    }
};