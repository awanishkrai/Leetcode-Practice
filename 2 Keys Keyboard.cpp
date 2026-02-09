class Solution {
public:
int m(int n,int len,int cop,vector<vector<int>>&memo){
    if(len>n)return 1000;
    if(len==n)return 0;
    if(memo[len][cop]!=-1)return memo[len][cop];
   int ans=min(1+m(n,len+cop,cop,memo),2+m(n,2*len,len,memo));
   return memo[len][cop]=ans;
}
    int minSteps(int n) {
        if(n==1)return 0;
        vector<vector<int>>memo(n,vector<int>(n,-1));
    return 1+m(n,1,1,memo);
    }
};