class Solution {
public:
    int solve(int n , int ind , int d , vector<vector<int>>&dp ,vector<int>& jobd){
        if(d == 1){
            return *max_element(begin(jobd)+ind,end(jobd));
        }
        if(dp[ind][d]!=-1) return dp[ind][d];
        int max_cur = INT_MIN;
        int res = INT_MAX;
        for(int i = ind ; i <= n-d ; i++){
            max_cur = max(max_cur,jobd[i]);
            res = min(res,max_cur + solve(n,i+1,d-1,dp,jobd));
        }
        return dp[ind][d] = res;
    }
    int minDifficulty(vector<int>& jobd, int d) {
        int n = jobd.size();
        if(d > n) return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return solve(n,0,d,dp,jobd);
    }
};