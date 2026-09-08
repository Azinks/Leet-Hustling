class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        int cnt = 0;
        if(n >= 1000 && n < 10000) {
            for(int i = 1000 ; i <= n ; i++){
                cnt++;
            }
        }
        if(n >= 10000 && n <= 100000){
            for(int i = 1000 ; i <= n ; i++){
                cnt++;
            }
        }
        return cnt;
    }
};