class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int score = 0;
        int deep = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                deep++;
            }
            else{
                deep--;
                if(s[i-1] == '('){
                    score += (1<<deep);
                }
            }
        }
        return score;
    }
};