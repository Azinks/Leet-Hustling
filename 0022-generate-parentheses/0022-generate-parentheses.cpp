class Solution {
public:
    vector<string>ans;
    bool vaildPara(string s){
        stack<char>st;
        int n = s.length();
        if(s[0] == ')') return false;
        if(s[n - 1] == '(') return false;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
    void solve(int n , string var){
        if(n == 0){
            if(vaildPara(var)){
                ans.push_back(var);
            }
            return;
        }
        var.push_back('(');
        solve(n - 1 , var);
        var.pop_back();
        var.push_back(')');
        solve(n - 1 , var);
        var.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solve(n * 2 , "");
        return ans;
    }
};