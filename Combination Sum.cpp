class Solution {
public:

void ts(vector<int>& candidates,int target,vector<vector<int>>&result,int sum,vector<int>ans,int start){
    int n=candidates.size();
    if(sum==target){
        result.push_back(ans);
    }
    if(sum>target){
        return;
    }
    for(int i=start;i<n;i++){
        ans.push_back(candidates[i]);
        ts(candidates,target,result,sum+candidates[i],ans,i);
        ans.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
         ts(candidates,target,result,0,ans,0);
         return result;
        
    }
};