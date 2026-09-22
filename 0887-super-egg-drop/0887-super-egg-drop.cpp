class Solution {
public:
    // int solve(int k, int n , vector<vector<int>>&dp){
    //     if(k == 1) return n;
    //     if(n == 0 || n == 1) return n;
    //     if(dp[k][n]!=-1) return dp[k][n];
    //     int mn = INT_MAX;
    //     for(int part = 1 ; part <= n ; part++){
    //         int tmp = 1 + max(solve(k - 1 , part - 1 , dp),solve(k , n - part , dp));
    //         mn = min(mn , tmp);
    //     }
    //     return dp[k][n] = mn;
    // }
    int superEggDrop(int k, int n) {

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    // Base cases
    for (int f = 0; f <= n; f++) {
        dp[1][f] = f;
    }

    for (int e = 1; e <= k; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    for (int e = 2; e <= k; e++) {

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

    return dp[k][n];
}
};