class Solution {
public:

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int row, int col, int delrow[], int delcol[]){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newr = x + delrow[i];
                int newc = y + delcol[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] != 1 && grid[newr][newc] == 1){
                    vis[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int numofcells;
        int n = grid.size();//no of row
        int m = grid[0].size();//no of col

        vector<vector<int>> vis(n,vector<int>(m,0));

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        //for row boundary traversal
        for(int j = 0; j<m; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                bfs(grid, vis, n, m, 0, j, delrow, delcol);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                bfs(grid, vis, n, m, n-1, j, delrow, delcol);
            }
        }

        //for column traversal
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                bfs(grid, vis, n, m, i, 0, delrow, delcol);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                bfs(grid, vis, n, m, i, m-1, delrow, delcol);
            }
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};