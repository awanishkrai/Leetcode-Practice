class Solution {
public:
    void generate(int n, int u, vector<string>& ans, string s) {
        if (n == 0 && u == 0) {
            ans.push_back(s);
            return;
        }
        if (u<0) return;
        if(n>0){
        generate(n - 1, u + 1, ans, s + '(');
        generate(n,     u - 1, ans, s + ')');
        }
        else{
            generate(n,     u - 1, ans, s + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, ans, "");
        return ans;
    }
};
