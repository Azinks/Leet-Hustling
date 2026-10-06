class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int open = 0;
        int close = 0;
        stack<char>st;
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else{
                // check for imbalance
                if(st.empty()){
                    res++;
                }
                //otherwise pop usually
                else{
                    st.pop();
                }
            }
            // if(open == close){
            //     res = max(res,open+close);
            // }
            // else if(close > open){
            //     open = 0;
            //     close = 0;
            // }
        }
        return st.size()+res;
    }
};