class Solution {
public:

int count(int n,long long sum,vector<int>&dp){
if(sum>n)return INT_MAX;
if(sum==n)return 0;
if(dp[sum]!=-1)return dp[sum];
int ans=INT_MAX;
for(long long i=1;i*i<=n;i++){
    int res=count(n,sum+i*i,dp);
    if(res!=INT_MAX)
    ans=min(ans,1+count(n,sum+i*i,dp));
}
return dp[sum]=ans;

}
    int numSquares(int n) {
        vector<int>dp(n,-1);
        
        return count(n,0,dp);
    }
};