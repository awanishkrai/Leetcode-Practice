class Solution {
public:
    bool isPalendrome(string s){
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return false;
        }
        return true;
    }
    void pp(string s,vector<string>&ans,vector<vector<string>>&result,int start){
        int n=s.length();
        if(start==n){
            result.push_back(ans);
        }
        if(start>n)return;
        for(int i=start;i<n;i++){
            string k= s.substr(start, i - start + 1);
            if(isPalendrome(k)){
                ans.push_back(k);
                pp(s,ans,result,i+1);
                ans.pop_back();
            }
            
        }

    }
    vector<vector<string>> partition(string s) {
    vector<vector<string>>result;
    vector<string>ans;
    pp(s,ans,result,0);
    return result;
    }
};