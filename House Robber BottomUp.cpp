class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>tabulation(n+1,0);
        tabulation[0]=nums[0];
        if(n>1){
             tabulation[1]=max(nums[0],nums[1]);
        }
        if(n>2){
       
        for(int i=2;i<n;i++){
            tabulation[i]=max(tabulation[i-1],nums[i]+tabulation[i-2]);
        }
        }
        return tabulation[n-1];
    }
};