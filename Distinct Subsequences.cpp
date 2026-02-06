class Solution {
public:
int nds(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    int result=0;
    if(j==t.length())return 1;
    if(i==s.length())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        result+=nds(i+1,j+1,s,t,dp)+nds(i+1,j,s,t,dp);
    }
    else{
        result+=nds(i+1,j,s,t,dp);
    }
    return dp[i][j]=result;
}
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
        return nds(0,0,s,t,dp);
    }
};