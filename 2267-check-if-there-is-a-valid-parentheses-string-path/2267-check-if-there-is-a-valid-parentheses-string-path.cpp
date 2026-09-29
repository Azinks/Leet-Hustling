class Solution {
public:
    bool solve(int i , int j , vector<vector<char>>& grid , int cnt , int n , int m , vector<vector<vector<int>>>&dp){   
        if(i == n - 1 && j == m - 1) return cnt == 1;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        if(grid[i][j] == '('){
            // cnt++;
            if(i + 1 < n && solve(i + 1 , j , grid , cnt + 1 , n , m , dp)){
                return dp[i][j][cnt] = true;
            }
            if(j + 1 < m && solve(i , j + 1 , grid , cnt + 1 , n , m , dp)){
                return dp[i][j][cnt] = true;
            }
        }
        else{
            // cnt--;
            if(cnt == 0) return dp[i][j][cnt] = false;
            if(i + 1 < n && solve(i + 1 , j , grid , cnt - 1 , n , m , dp)){
                return dp[i][j][cnt] = true;
            }
            if(j + 1 < m && solve(i , j + 1 , grid , cnt - 1 , n , m , dp)){
                return dp[i][j][cnt] = true;
            }

        }
        return dp[i][j][cnt] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == ')') return false;
        if(grid[n-1][m-1] == '(') return false;
        vector<vector<vector<int>>>dp(n + 1 , vector<vector<int>>(m + 1 , vector<int>(1001 , -1)));
        return solve(0,0,grid,0,n,m,dp);
    }
};