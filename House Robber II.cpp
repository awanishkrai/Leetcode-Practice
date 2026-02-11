class Solution {
public:

int maxrob(vector<int>&nums,bool prevt,bool zerot,int i, vector<vector<vector<int>>>&dp){
    
    if(i>=nums.size())return 0;
    if(i==nums.size()-1 && zerot==true)return 0;
    if(dp[i][prevt][zerot]!=-1)return dp[i][prevt][zerot];
    int ans=0;
    if(i==0){
        
      int take=nums[i]+maxrob(nums,true,true,i+1,dp);
        
        int nottake=maxrob(nums,false,false,i+1,dp);
        ans=max(take,nottake);  
    }
    else if(!prevt){
        
        int take=nums[i]+maxrob(nums,true,zerot,i+1,dp);
        
        int nottake=maxrob(nums,false,zerot,i+1,dp);
        ans=max(take,nottake);
    }
    else{
        ans=max(ans,maxrob(nums,false,zerot,i+1,dp));
    }
    return dp[i][prevt][zerot]=ans;
}
    int rob(vector<int>& nums) {
       int n=nums.size();
         vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(2, -1))
    );


        bool prevt=false;
        bool zerot=false;

        return maxrob(nums,prevt,zerot,0,dp);
    }
};