class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>premax(n);
        vector<int>premin(n);
        premax[0] = nums[0];
        premin[0] = *min_element(nums.begin() , nums.end());
        for(int i = 1 ; i < n ; i++){
            premax[i] = max(premax[i-1],nums[i]);
            premin[i] = *min_element(nums.begin() + i , nums.end());
        }
        int ans = 200;
        for(int i = 0 ; i < n ; i++){
            int max = premax[i];
            int min = premin[i];
            int res = max - min;
            if(res <= k && i < ans){
                ans = i;
            }
        }
        if(ans == 200) return -1;
        return ans;
    }
};