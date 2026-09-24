class Solution {
public:
    int sumOfDigits(int n){
        int x = n;
        int sum = 0;
        while(x > 1){
            int digit = x % 10;
            sum += digit;
            x = x / 10;
        }
        if(x == 1) sum++;
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int sum = sumOfDigits(nums[i]);
            if(sum == i) return i;
        }
        return -1;
    }
};