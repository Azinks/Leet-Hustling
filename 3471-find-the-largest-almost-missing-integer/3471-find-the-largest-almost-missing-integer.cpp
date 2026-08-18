class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>hash(51,0);
        int n = nums.size();
        if(k == n) return *max_element(nums.begin(),nums.end());
        for(int i = 0 ; i <= n-k ; i++){
            int size_sub = i + k;
            for(int j = i ; j < size_sub ; j++){
                hash[nums[j]]++;
            }
        }
        for(int i = 50 ; i >= 0 ; i--){
            if(hash[i] == 1){
                return i;
            }
        }
        return -1;
    }
};