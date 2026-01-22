class Solution {
public:
int find_maximum(vector<int>&nums,int mid){
    int count=0;
    int sum=0;
    for(int i=0;i<nums.size();i++){
         if (nums[i] > mid) return 1e9;  
        if(sum+nums[i]>mid){
            sum=nums[i];
            count++;
        }
        else{
            sum+=nums[i];
        }

    }
if (sum > 0) count++; 

    
    return count;
}
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=accumulate(nums.begin(),nums.end(),0);
        while(l<r){
            int mid=(l+r)/2;
            int ans=find_maximum(nums,mid);
            if(ans<=k){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};