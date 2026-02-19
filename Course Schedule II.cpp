class Solution {
public:
//directed edges are given in revrsed order we must make the graph in same way
//we must have single connected componente for topological sort
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>result;
        int n=numCourses;
        for(int i=0;i<prerequisites.size();i++){
            int a,b;
            a=prerequisites[i][0];
            b=prerequisites[i][1];
            adj[b].push_back(a);
                    }
            for(int i=0;i<n;i++){
                for(int j=0;j<adj[i].size();j++){
                        indegree[adj[i][j]]++;
                  
                }
            }
            queue<int>q;
            for(int i=0;i<n;i++){
                if(indegree[i]==0){
                    q.push(i);
                    result.push_back(i);
                }
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push(v);
                        result.push_back(v);
                    }
                }
            }

            if(result.size()!=numCourses)return {};
          return result;
    }
};