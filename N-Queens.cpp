class Solution {
public:
void nqueens(int n,vector<vector<string>>&result,vector<string>&ans,int count=0){
if(n==count){ result.push_back(ans);
return;
}

for(int j=0;j<n;j++){
    bool canPlace=true;
    int u=count-1;
    while(u>=0){
        if(ans[u][j]!='.'){
            canPlace =false;
            break;
        }
        u--;
    }
    int g;
    u=count-1;
    g=j-1;
    while(u>=0 && g>=0){
        if(ans[u][g]!='.'){
            canPlace=false;
            break;
        }
        u--;
        g--;

    }
    u=count-1;
    g=j+1;
    while(u>=0 && g<n){
        if(ans[u][g]!='.'){
            canPlace=false;
            break;
        }
        u--;
        g++;

    }
    if(canPlace){
        string s="";
        for(int z=0;z<n;z++){
            s+='.';
        }
        s[j]='Q';
        ans.push_back(s);
        nqueens(n,result,ans,count+1);
        ans.pop_back();
    }
    else{
        continue;
    }

}

}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>ans;
        nqueens(n,result,ans,0);
        return result;
    }
};