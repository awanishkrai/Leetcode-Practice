class Solution {
public:
bool search(vector<vector<char>>& board,string word,int u,int i,int j,vector<vector<bool>>&visited){
    int m=board.size();
    int n=board[0].size();
    if(i <0 || i>=m){
        return false;
    }
    if(j<0 ||j>=n){
        return false;
    }
    if(visited[i][j]){
        return false;
    }
    
    
    if(u==word.length())return true;
    if(board[i][j]==word[u]){
        visited[i][j]=true;
        u++;
    }
    else{
        return false;
    }
     if(u==word.length())return true;
    bool found=(search(board,word,u,i-1,j,visited)||
    search(board,word,u,i+1,j,visited)||
    search(board,word,u,i,j+1,visited)||
    search(board,word,u,i,j-1,visited));
     visited[i][j]=false;
     return found;
}
    bool exist(vector<vector<char>>& board, string word) {
         int m=board.size();
    int n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        bool ans=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=(ans||search(board,word,0,i,j,visited));
            }
        }
        return ans;
    }
};