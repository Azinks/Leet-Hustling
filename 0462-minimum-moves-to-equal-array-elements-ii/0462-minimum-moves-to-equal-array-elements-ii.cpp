class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int mid = nums[nums.size() / 2];
        for(int &num : nums){
            ans += abs(num - mid);
        }
        return ans;
    }
};