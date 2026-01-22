\class Solution {
public:
int count_days(vector<int>& arr,int mid){
    int n=arr.size();
    int sum=0;
    int count=0;
for(int i=0;i<n;i++){
    if(arr[i]>mid){
        return 1e9;
    }
    else if(sum+arr[i]==mid){
        sum=0;
        count++;
    }
    else if(sum+arr[i]>mid){
        
            count++;
        
        sum=arr[i];
       
        
    }
    else{
        sum+=arr[i];
    }
    
}
if (sum > 0) count++;
return count;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int r=accumulate(weights.begin(),weights.end(),0);
        while(l<r){
            int mid=(l+r)/2;
            int ans=count_days(weights,mid);
            if (ans <= days) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};