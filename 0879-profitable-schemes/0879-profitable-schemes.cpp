class Solution {
public:
    int MOD = 1e9+7;
    int solve(int ind , int pro , int people ,int n, int minProfit, vector<int>& group, vector<int>& profit,vector<vector<vector<int>>>&dp){
        if(people > n) return 0;
        if(ind == group.size()){
            if(pro >= minProfit) return 1;
            return 0;
        }
        if(dp[ind][pro][people]!=-1) return (dp[ind][pro][people])%MOD;
        //take this index--->
        int take = solve(ind+1,min(minProfit,pro+profit[ind]),people+group[ind],n,minProfit,group,profit,dp);
        //not_to_take this index--->
        int not_take = solve(ind+1,pro,people,n,minProfit,group,profit,dp);
        return dp[ind][pro][people] = (take + not_take)%MOD;

    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>>dp(group.size()+1,vector<vector<int>>(101,vector<int>(101,-1)));
        return solve(0,0,0,n,minProfit,group,profit,dp);
    }
};