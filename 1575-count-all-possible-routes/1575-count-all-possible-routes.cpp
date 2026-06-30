class Solution {
public: 
    int MOD = 1e9+7;
    int solve(vector<int>& locations, int ind, int finish, int fuel,int n,vector<vector<int>>&dp){
        if(fuel < 0) return 0;
        if(dp[ind][fuel]!=-1) return dp[ind][fuel];
        int ans = 0;
        if(ind == finish){
            ans+=1;
        }
        for(int j = 0 ; j < n ; j++){
            if(j!=ind){
                int remain = fuel - abs(locations[ind]-locations[j]);
                ans = (ans + solve(locations,j,finish,remain,n,dp))%MOD;
            }
        }
        return dp[ind][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>>dp(n + 1 ,vector<int>(fuel + 1 , -1));
        return solve(locations,start,finish,fuel,n,dp);
    }
};