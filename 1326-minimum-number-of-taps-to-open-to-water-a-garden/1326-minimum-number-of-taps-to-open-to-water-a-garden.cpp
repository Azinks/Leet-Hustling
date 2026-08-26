class Solution {
public:
    int solve(int ind , int maxDepth , vector<pair<int,int>>& range , int n , map<pair<int,int>,int>&dp){
        if (maxDepth >= n)

            return 0;

        if (ind >= range.size()){

            return 1e9;
        }
        if(dp.find({ind,maxDepth})!=dp.end()) return dp[{ind,maxDepth}];
        if(range[ind].first > maxDepth) return dp[{ind,maxDepth}] = 1e9;
        int not_take = solve(ind + 1 , maxDepth , range , n , dp);
        int take = 1 + solve(ind + 1 , max(maxDepth,range[ind].second) , range , n , dp);
        return dp[{ind,maxDepth}] = min(take,not_take);
    } 
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>range;
        for(int i = 0 ; i <= n ; i++){
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            range.push_back({start,end});
        }
        map<pair<int,int>,int>dp;
        sort(begin(range),end(range));
        int res = solve(0,0,range,n,dp);
        return res == 1e9 ? -1 : res;
    }
};