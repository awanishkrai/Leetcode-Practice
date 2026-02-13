class Solution {
public:
int tr(vector<int>& heights,int i,vector<int>&dp,vector<int>&left,vector<int>&right){
    if(i<0 || i>=heights.size())return 0;
    if(dp[i]!=-1)return dp[i];
   

    int u=min(left[i],right[i]);
    int sum=0;
    sum=u-heights[i];
    
    return dp[i]=sum+tr(heights,i+1,dp,left,right);

}
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>dp(height.size(),-1);
        vector<int>left(n),right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        return tr(height,0,dp,left,right);
    }
};