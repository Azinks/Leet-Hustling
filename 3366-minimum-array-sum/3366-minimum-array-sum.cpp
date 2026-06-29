class Solution {
public:
    int solve(int ind,vector<int>& nums, int k, int op1, int op2,int n,vector<vector<vector<int>>>&dp){
        if(ind == n){
            return 0;
        }
        if(dp[ind][op1][op2]!=-1) return dp[ind][op1][op2];
        int ans = nums[ind] + solve(ind+1, nums, k, op1, op2, n, dp);

        if(op1 > 0){
            ans = min(ans,
                    (nums[ind] + 1)/2 +
                    solve(ind+1, nums, k, op1-1, op2, n, dp));
        }

        if(op2 > 0 && nums[ind] >= k){
            ans = min(ans,
                    nums[ind]-k +
                    solve(ind+1, nums, k, op1, op2-1, n, dp));
        }
        if(op1 > 0 && op2 > 0){
            int x = (nums[ind] + 1)/2;
            if(x >= k){
                ans = min(ans,x-k + solve(ind+1, nums, k, op1-1, op2-1, n, dp));
            }
        }
        if(op1 > 0 && op2 > 0 && nums[ind] >= k){
            int y = nums[ind]-k;
            y = (y+1)/2;
            ans = min(ans,y+solve(ind+1, nums, k, op1-1, op2-1, n, dp));
        }
        return dp[ind][op1][op2] = ans;
        
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        cout<< 11/2;
        vector<vector<vector<int>>>dp(n + 1 ,vector<vector<int>>(op1 + 1 , vector<int>(op2 + 1 , -1)));
        return solve(0,nums,k,op1,op2,n,dp);
    }
};