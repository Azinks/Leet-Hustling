class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        if(nums[0] == 0 && nums.size() == 1){
            return 0;
        }
        int ans = 0;
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                cnt++;
            }
        }
        if(cnt == nums.size()){
            return 0;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            ans = ans ^ nums[i];
        }
        if(ans == 0){
            return nums.size() - 1;
        }
        return nums.size();
    }
};