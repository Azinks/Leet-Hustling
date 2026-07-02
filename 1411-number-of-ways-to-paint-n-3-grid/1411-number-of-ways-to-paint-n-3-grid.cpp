class Solution {
public:
    int MOD = 1e9+7;

    int solve(int n, int prev,
              vector<vector<int>>& dp,
              vector<string>& states) {

        if (n == 0)
            return 1;

        if (dp[n][prev] != -1)
            return dp[n][prev];

        int res = 0;

        for (int i = 0; i < 12; i++) {

            if (i == prev)
                continue;

            bool ok = true;

            for (int j = 0; j < 3; j++) {
                if (states[i][j] == states[prev][j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                res = (res + solve(n - 1, i, dp, states)) % MOD;
            }
        }

        return dp[n][prev] = res;
    }

    int numOfWays(int n) {

        vector<string> states = {
            "RYG","RGY","RYR","RGR",
            "YRG","YGR","YGY","YRY",
            "GRY","GYR","GRG","GYG"
        };

        vector<vector<int>> dp(n + 1, vector<int>(12, -1));

        int ans = 0;

        for (int i = 0; i < 12; i++) {
            ans = (ans + solve(n - 1, i, dp, states)) % MOD;
        }

        return ans;
    }
};