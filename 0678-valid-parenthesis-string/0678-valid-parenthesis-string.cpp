class Solution {
public:
    bool solve(int ind, string& s, int n, int open, int close,
               vector<vector<vector<int>>>& dp) {
        if (close > open) return false;
        if (ind == n) return open == close;

        if (dp[ind][open][close] != -1) {
            return dp[ind][open][close];
        }

        bool ans;

        if (s[ind] == '(') {
            ans = solve(ind + 1, s, n, open + 1, close, dp);
        } else if (s[ind] == ')') {
            ans = solve(ind + 1, s, n, open, close + 1, dp);
        } else { // '*'
            ans = solve(ind + 1, s, n, open + 1, close, dp) ||
                  solve(ind + 1, s, n, open, close + 1, dp) ||
                  solve(ind + 1, s, n, open, close, dp);
        }

        return dp[ind][open][close] = ans;
    }

    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1))
        );

        return solve(0, s, n, 0, 0, dp);
    }
};