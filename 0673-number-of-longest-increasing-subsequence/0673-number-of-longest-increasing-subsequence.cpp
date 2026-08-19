class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n+1,1);
        vector<int>cnt(n+1,1);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    if(temp[j] + 1 == temp[i]){
                        cnt[i] = cnt[i] + cnt[j];
                    }
                    else if(temp[j] + 1 > temp[i]){
                        temp[i] = temp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
        }
        int maxi = *max_element(temp.begin() , temp.end());
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(temp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};