class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int dist = ans[x][y];
            q.pop();

            for(int i = 0; i<4; i++){
                int newr = x + delrow[i];
                int newc = y + delcol[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] != 1){
                    ans[newr][newc] = dist + 1;
                    vis[newr][newc] = 1;
                    q.push({newr,newc});
                }
            }
        }
        return ans;
    }
};