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
         if (i > start && candidates[i] == candidates[i - 1]) continue;
        ans.push_back(candidates[i]);

        ts(candidates,target,result,sum+candidates[i],ans,i+1);
        ans.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>ans;
         ts(candidates,target,result,0,ans,0);
         return result;
        
    }
};