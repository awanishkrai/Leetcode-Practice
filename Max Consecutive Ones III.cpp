class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int max_count=0;
        int n=nums.size();
        int z=0;
        int l=0;
        int r=0;
        while(r<n){
            if(nums[r]==1){
                count++;
                max_count=max(max_count,count);
            }
            else{
                if(z<k){
                    z++;
                    count++;
                    max_count=max(max_count,count);
                }
                else{
                    while(z>=k){
                        if(nums[l]==0){
                            z--;
                        }
                        count--;
                        l++;
                        
                        
                    }
                    z++;
                    count++;
                    max_count=max(max_count,count);
                }
            }
            cout<<count<<" "<<z<<endl;
            r++;
            
        }
        return max_count;
    }
};