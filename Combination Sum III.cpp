class Solution {
public:

    void combo(int k,int n,vector<vector<int>>&result,vector<int>ans,int sum,int start){
        if(sum==n && ans.size()==k){
            result.push_back(ans);
            return;
        }
        if(sum>n || ans.size()>k)return;
        for(int i=start;i<=min(n,9);i++){
            ans.push_back(i);
            combo(k,n,result,ans,sum+i,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>ans;
        combo(k,n,result,ans,0,1);
        return result;
    }
};