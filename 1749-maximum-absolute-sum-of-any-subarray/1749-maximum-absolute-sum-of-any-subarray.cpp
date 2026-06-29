class Solution {
public:

    // Finds the minimum subarray sum
    int minSum(vector<int>& nums, int n) {

        int ans = nums[0];
        int bestEnding = nums[0];

        for (int i = 1; i < n; i++) {

            int startNew = nums[i];
            int extendPrevious = bestEnding + nums[i];

            bestEnding = min(startNew, extendPrevious);

            ans = min(ans, bestEnding);
        }

        return -ans;
    }

    // Finds the maximum subarray sum
    int maxSum(vector<int>& nums, int n) {

        int ans = nums[0];
        int bestEnding = nums[0];

        for (int i = 1; i < n; i++) {

            int startNew = nums[i];
            int extendPrevious = bestEnding + nums[i];

            bestEnding = max(startNew, extendPrevious);

            ans = max(ans, bestEnding);
        }

        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        int maximum = maxSum(nums, n);
        int minimum = minSum(nums, n);

        return max(maximum, minimum);
    }
};