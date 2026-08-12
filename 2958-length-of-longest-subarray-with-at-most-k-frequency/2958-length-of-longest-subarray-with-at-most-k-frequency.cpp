class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int l = 0;
        int len = 0;

        for (int r = 0; r < n; r++) {

            mpp[nums[r]]++;

            while (mpp[nums[r]] > k) {
                mpp[nums[l]]--;
                l++;
            }

            len = max(len, r - l + 1);
        }

        return len;
    }
};