class Solution {
public:
    int solve(const string& s, int k, int ind, int prev,
              vector<vector<int>>& dp) {
        if (ind == s.length()) return 0;

        int& ans = dp[ind][prev + 1];
        if (ans != -1) return ans;

        int not_take = solve(s, k, ind + 1, prev, dp);

        int current = s[ind] - 'a';
        int take = 0;

        if (prev == -1 || abs(current - prev) <= k) {
            take = 1 + solve(s, k, ind + 1, current, dp);
        }

        return ans = max(take, not_take);
    }

    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length(), vector<int>(27, -1));
        return solve(s, k, 0, -1, dp);
    }
};