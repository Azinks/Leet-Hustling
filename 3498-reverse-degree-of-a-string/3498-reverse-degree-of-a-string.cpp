class Solution {
public:
    int reverseDegree(string s) {
        cout<<s[0] - 'z';
        int n = s.length();
        int ans = 0;
        for(int i = 0 ; i < n  ; i++){
            int val = abs(s[i] - 'z') + 1;
            ans = ans + (val * (i + 1));
        }
        return ans;
    }
};