class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(26,0);
        for(char c : s){
            int curr = c - 'a';
            int maxi = INT_MIN;
            for(int i = max(0,curr-k) ; i <= min(25,curr+k) ; i++){
                if(dp[i] > maxi){
                    maxi = dp[i];
                }
            }
            dp[curr] = maxi + 1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};