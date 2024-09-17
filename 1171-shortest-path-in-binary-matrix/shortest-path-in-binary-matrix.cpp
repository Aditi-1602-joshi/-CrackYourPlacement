class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        queue<pair<int,pair<int,int>>> q;
        if(n == 1 && grid[0][0] == 0)return 1;//if one cell and its 0
        if(n == 1 && grid[0][0] == 1) return -1;//if one cell and its 1
        
        if(grid[n-1][n-1] == 1 || grid[0][0] == 1)return -1;//if start or/and dest = 1

        q.push({1,{0,0}});
        dist[0][0] = 1;
        int dr[] = {-1,-1,0,1,1,1,0,-1};
        int dc[] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            for(int i = 0; i<8; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && (dis+1)<dist[nr][nc]){
                    dist[nr][nc] = dis+1;
                    if(nr == n-1 && nc == n-1)return dis+1;
                    q.push({dis+1,{nr,nc}});
                }
            }
        }
        
        return -1;
    }
};