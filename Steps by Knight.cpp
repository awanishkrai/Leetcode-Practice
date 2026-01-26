class Solution {
public:
  
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        int ex = targetPos[0] - 1;
        int ey = targetPos[1] - 1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{sx,sy},0});
        visited[sx][sy] = true;
        vector<int> x = {2,2,-2,-2,1,1,-1,-1};
        vector<int> y = {1,-1,1,-1,2,-2,2,-2};
        while(!q.empty()){
            auto p = q.front();   
            q.pop();             
            int nx = p.first.first;
            int ny = p.first.second;
            int dist = p.second;
            for(int i = 0; i < 8; i++){
                int xi = nx + x[i];
                int yi = ny + y[i];
                if(xi == ex && yi == ey){
                    return dist + 1;  
                }
                if(xi>=0 && yi>=0 && xi<n && yi<n && !visited[xi][yi]){
                    visited[xi][yi] = true;
                    q.push({{xi,yi},dist+1});
                }
            }
        }
        return 0;
    }
};
