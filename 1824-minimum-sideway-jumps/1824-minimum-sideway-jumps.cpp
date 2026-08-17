class Solution {
public:
    int solve(vector<int>& ob,int ind, int lane,int n,vector<vector<int>>&dp){
        if(ind == n) return 0;
        if(dp[ind][lane]!=-1) return dp[ind][lane];
        if(ob[ind+1]!=lane){
            return solve(ob,ind+1,lane,n,dp);
        }
        else{
            int ans = INT_MAX;
            for(int i = 1 ; i <= 3 ; i++){
                if(lane != i && ob[ind]!=i){
                    ans = min(ans,1+solve(ob,ind,i,n,dp));
                }
            }
            return dp[ind][lane] = ans;
        }
    }
    int minSideJumps(vector<int>& ob) {
        int n = ob.size() - 1;
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(ob,0,2,n,dp);
    }
};