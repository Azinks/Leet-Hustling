class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int len = s.length();
        int i = 0;
        int size_ans = 0;
        while(i < len){
            if(s[i] == '('){
                st.push(s[i]);
                size_ans = max(size_ans,(int)st.size());
            }
            if(s[i] == ')'){
                // size_ans = max(size_ans,st.size());
                st.pop();
            }
            i++;
        }
        return size_ans;
    }
};