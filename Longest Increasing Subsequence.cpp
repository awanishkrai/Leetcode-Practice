class Solution {
public:
int lis(vector<int>&nums,int i,vector<int>&dp){
    int n=nums.size();
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int maxlen=1;
    for(int j=i+1;j<n;j++){
        if(nums[i]<nums[j]){
            maxlen=max(maxlen,1+lis(nums,j,dp));
        }

    }
    return dp[i]=maxlen;
   

}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n+1,-1);
        int ans=0;
        for(int i=0;i<n;i++){
           ans=max( ans,lis(nums,i,dp));
        }
        return ans;
    }
};