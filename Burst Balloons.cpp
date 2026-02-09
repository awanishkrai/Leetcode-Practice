class Solution {
public:
int coins(int l,int r,vector<int>&nums,vector<vector<int>>&dp){
    if(l>r)return 0;
    int result=0;
    if(dp[l][r]!=-1)return dp[l][r];
    for(int i=l;i<=r;i++){
        result=max(result,nums[i]*nums[l-1]*nums[r+1]+coins(l,i-1,nums,dp)+coins(i+1,r,nums,dp));
    }
    return dp[l][r]=result;
    
}
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int l=1;
        int r=nums.size()-2;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return coins(l,r,nums,dp);
    }
};