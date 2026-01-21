class Solution {
public:
    int check_devisor(vector<int>&nums,int mid){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%mid==0){
                sum+=nums[i]/mid;
            }
            else{
                sum+=nums[i]/mid;
                sum++;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=(l+r)/2;
            int k=check_devisor(nums,mid);
            if(k<=threshold){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};