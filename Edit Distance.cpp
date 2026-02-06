class Solution {
public:

int ed(string w1,string w2,int l,int r,vector<vector<int>>&dp){
    int ans=0;
    if(l<0)return r+1;
    if(r<0)return l+1;
    if(dp[l][r]!=-1)return dp[l][r];
    if(w1[l]==w2[r]){
        ans=ed(w1,w2,l-1,r-1,dp);
    }
    else{
        ans=1+min({ed(w1,w2,l-1,r,dp),ed(w1,w2,l,r-1,dp),ed(w1,w2,l-1,r-1,dp)});
    }
    return dp[l][r]=ans;
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return ed(word1,word2,word1.size(),word2.size(),dp);
    }
};