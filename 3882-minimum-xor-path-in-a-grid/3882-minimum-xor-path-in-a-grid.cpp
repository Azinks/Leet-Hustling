class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bitset<1024>>>dp(n,vector<bitset<1024>>(m));

        dp[0][0][grid[0][0]] = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                bitset<1024>up;
                bitset<1024>left;
                if(i > 0) {
                    up = dp[i - 1][j];
                }
                if(j > 0){
                    left = dp[i][j - 1];
                }
                bitset<1024>comInd = up | left;
                for(int k = 0 ; k < 1024 ; k++){
                    if(comInd[k]){
                        int atInd = grid[i][j] ^ k;
                        dp[i][j][atInd] = 1;
                    }
                }
            }
        }
        for(int val = 0 ; val < 1024 ; val++){
            if(dp[n-1][m-1][val]){
                return val;
            }
        }
        return -1;
    }
};