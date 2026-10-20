class Solution {
private:
    vector<vector<pair<int,int>>> dp;

    pair<int,int> memoize(int idx, int prevIdx, vector<int> &nums){

        if(idx < 0) return {0, 1};

        if(dp[idx][prevIdx].first != -1)
            return dp[idx][prevIdx];

        // NOT TAKE
        pair<int,int> nottake = memoize(idx-1, prevIdx, nums);

        // TAKE
        pair<int,int> take = {-1000000000, 0};
        if(prevIdx == nums.size() || nums[idx] < nums[prevIdx]) {
            take = memoize(idx-1, idx, nums);
            take.first = 1 + take.first;
        }

        // MERGE
        if(take.first > nottake.first)
            return dp[idx][prevIdx] = take;
        else if(take.first < nottake.first)
            return dp[idx][prevIdx] = nottake;
        else
            return dp[idx][prevIdx] =
                   {take.first, take.second + nottake.second};
    }

public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        dp.assign(n, vector<pair<int,int>>(n+1, {-1, -1}));

        pair<int,int> ans = memoize(n-1, n, nums);
        return ans.second;
    }
};