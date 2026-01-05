class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
int ans=1;
        vector<int>dp(n+1,1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(nums[i-1]>nums[j-1]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
                
            }
            ans = max(ans, dp[i]);    
        }
        return ans;
    }
};