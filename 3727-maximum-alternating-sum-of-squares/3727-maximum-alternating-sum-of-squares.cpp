class Solution {
public:
    // static bool comp(int a , int b){
    //     return a > b;
    // }
    long long maxAlternatingSum(vector<int>& nums) {
        long long res = 0;
        if(nums.size() < 2) return nums[0]*nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = (nums[i]*nums[i]);
        }
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            if(start == end){
                res += nums[start];
                break;
            }
            res += nums[end] - nums[start];
            start++;
            end--; 
        }
        cout<<nums[0]<<" "<<nums[1];
        return res;
    }
};