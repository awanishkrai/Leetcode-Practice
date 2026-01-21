class Solution {
public:
    int count_flowers(vector<int>& bloomDay,int mid,int k){
        int count=0;
        int bqt=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(mid>=bloomDay[i]){
                count++;
            }
            else{
                count=0;
            }
            if(count==k){
                bqt++;
                count=0;
            }
        }
        return bqt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long u=1LL*m*k;
        if(u>bloomDay.size())return -1;
        int l=0;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        while(l<r){
            int mid=(l+r)/2;
            int btq=count_flowers(bloomDay,mid,k);
            if(btq>=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};