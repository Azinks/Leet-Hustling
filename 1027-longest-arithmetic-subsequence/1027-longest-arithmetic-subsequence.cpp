class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1001, 0));

        int ans = 2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                int diff = nums[i] - nums[j];

                // diff ranges from -500 to 500
                int d = diff + 500;

                if(dp[j][d] == 0)
                    dp[i][d] = 2;
                else
                    dp[i][d] = dp[j][d] + 1;

                ans = max(ans, dp[i][d]);
            }
        }

        return ans;
    }
};