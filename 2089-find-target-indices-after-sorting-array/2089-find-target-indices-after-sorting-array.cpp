class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        int n = static_cast<int>(nums.size());
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                int left = mid;
                int right = mid;

                while (left > 0 && nums[left - 1] == target) {
                    --left;
                }
                while (right + 1 < n && nums[right + 1] == target) {
                    ++right;
                }

                for (int i = left; i <= right; ++i) {
                    ans.push_back(i);
                }
                return ans;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};