class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[idx][prevIdx] = {length, count}
        vector<vector<pair<int,int>>> dp(
            n, vector<pair<int,int>>(n+1, {0,0})
        );

        // Base: idx = -1 → length 0, count 1
        // We simulate this by initializing dp[0][*] carefully later

        for(int prev = 0; prev <= n; prev++){
            dp[0][prev] = {0,1};
            if(prev == n || nums[0] < nums[prev]){
                dp[0][prev] = {1,1};
            }
        }

        // Build table
        for(int idx = 1; idx < n; idx++){

            for(int prev = 0; prev <= n; prev++){

                // NOT TAKE
                pair<int,int> nottake = dp[idx-1][prev];

                // TAKE
                pair<int,int> take = {-1000000000, 0};
                if(prev == n || nums[idx] < nums[prev]){
                    take = dp[idx-1][idx];
                    take.first += 1;
                }

                // MERGE
                if(take.first > nottake.first)
                    dp[idx][prev] = take;
                else if(take.first < nottake.first)
                    dp[idx][prev] = nottake;
                else
                    dp[idx][prev] =
                        {take.first, take.second + nottake.second};
            }
        }

        return dp[n-1][n].second;
    }
};