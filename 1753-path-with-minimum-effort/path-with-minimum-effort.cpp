class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int numrow = heights.size();
        int numcol = heights[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(numrow,vector<int>(numcol,1e9));

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int currrow = pq.top().second.first;
            int currcol = pq.top().second.second;
            int currdis = pq.top().first;
            pq.pop();
            if(currrow == (numrow-1) && currcol == (numcol-1))return currdis;
            for(int i = 0; i<4; i++){
                int newr = currrow + delrow[i];
                int newc = currcol + delcol[i];
                
                if(newr >= 0 && newr < numrow && newc >= 0 && newc < numcol){
                    int neweffort = max(abs(heights[newr][newc] - heights[currrow][currcol]),currdis);

                    if(neweffort < dist[newr][newc]){
                        dist[newr][newc] = neweffort;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};