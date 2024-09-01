class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        // first creating adjacency list and indegree
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<int> topo;
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
            topo.push_back(node);
        }

        if(numCourses == topo.size()){
            return true;
        }
        return false;
    }
};