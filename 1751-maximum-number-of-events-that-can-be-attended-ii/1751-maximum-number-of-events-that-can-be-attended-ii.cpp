class Solution {
public:
    int nextGreater(vector<vector<int>>&arr,int start,int target){
        int end = arr.size() - 1;
        int res = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid][0] > target){
                res = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1; 
            }
        } 
        return res;
    }
    int solve(vector<vector<int>>&arr,int ind,vector<vector<int>>&dp,int k){
        if(ind >= arr.size() || k == 0) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int next = nextGreater(arr , ind + 1 , arr[ind][1]);
        int taken = arr[ind][2] + solve(arr,next,dp,k-1);
        int not_taken = solve(arr, ind + 1,dp,k);
        return dp[ind][k] = max(taken,not_taken);
    }
    int maxValue(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(arr.begin(),arr.end());
        return solve(arr,0,dp,k);
    }
};