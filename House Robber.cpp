class Solution {
public:
int rob(vector<int>&nums,int limit,vector<int>&dp){
    int n=nums.size();

    if(limit>=n){
        return 0;
    }
    if(dp[limit]!=-1)return dp[limit];
    int r1=nums[limit]+rob(nums,limit+2,dp);
    int r2=rob(nums,limit+1,dp);
    int result=max(r1,r2);
    return dp[limit]= result;
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int result=rob(nums,0,dp);
        return result;
    }
};