class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int ind1,int ind2,int n,int m,vector<vector<int>>&dp){
        if(ind1 == n || ind2 == m){
            return -1e9;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int val = nums1[ind1] * nums2[ind2];
        int take_ij = nums1[ind1] * nums2[ind2] + solve(nums1,nums2,ind1+1,ind2+1,n,m,dp);
        int take_i = solve(nums1,nums2,ind1+1,ind2,n,m,dp);
        int take_j = solve(nums1,nums2,ind1,ind2+1,n,m,dp);
        return dp[ind1][ind2] = max(max(val,take_ij),max(take_i,take_j));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(nums1,nums2,0,0,n,m,dp);
    }
};