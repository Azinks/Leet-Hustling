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

    vector<int> dp(k + 1, 0);

    int moves = 0;

    while (dp[k] < n) {

        moves++;

        for (int eggs = k; eggs >= 1; eggs--) {
            dp[eggs] = dp[eggs] + dp[eggs - 1] + 1;
        }
    }

    return moves;
}
};