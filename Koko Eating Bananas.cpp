class Solution {
public:
int find_hours(vector<int>& piles,int k){
    int hours=0;
for(int i=0;i<piles.size();i++){
    if(piles[i]%k==0){
        hours+=piles[i]/k;
    }
    else{
        hours+=piles[i]/k;
        hours++;

    }
}
return hours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int k=*max_element(piles.begin(), piles.end());

        int l=1;
        int r=k;
        while(l<r){
            int mid=(l+r)/2;
            int ans=find_hours(piles,mid);
            
            if(ans<=h){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};