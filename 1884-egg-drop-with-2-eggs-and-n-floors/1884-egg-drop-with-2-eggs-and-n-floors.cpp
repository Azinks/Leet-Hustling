class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1, 0));

    // Base cases
    for (int f = 0; f <= n; f++) {
        dp[1][f] = f;
    }

    for (int e = 1; e <= 2; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    for (int e = 2; e <= 2; e++) {

        for (int f = 2; f <= n; f++) {

            int lo = 1;
            int hi = f;

            int ans = INT_MAX;

            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                int eggBreaks = dp[e - 1][mid - 1];
                int eggSurvives = dp[e][f - mid];

                int worst = 1 + max(eggBreaks, eggSurvives);

                ans = min(ans, worst);

                // egg breaks case is smaller
                // Move right to increase it
                if (eggBreaks < eggSurvives) {
                    lo = mid + 1;
                }
                else {
                    // egg breaks >= survives
                    // Move left
                    hi = mid - 1;
                }
            }

            dp[e][f] = ans;
        }
    }

    return dp[2][n];
    }
};