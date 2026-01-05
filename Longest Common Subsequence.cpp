class Solution {
public:
int compare(string& text1,string& text2,int i,int j,vector<vector<int>>&dp){
    int n=text1.size();
    int m=text2.size();
    if(i==n ||j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        
        return dp[i][j] =1+compare(text1,text2,i+1,j+1,dp);
    }
    else{
        return dp[i][j]= max(
        compare(text1,text2,i,j+1,dp),
        compare(text1,text2,i+1,j,dp)
        );
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
    int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return compare(text1,text2,0,0,dp);
    }
};