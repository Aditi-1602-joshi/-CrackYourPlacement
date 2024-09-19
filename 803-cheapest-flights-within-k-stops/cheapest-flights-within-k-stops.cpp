class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        //ceating adjacency list
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        //q(stops,node,dist)

        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()){
            int currnode = q.front().second.first;
            int currstops = q.front().first;
            int currcost = q.front().second.second;

            q.pop();

            if(currstops > k)continue;
            for(auto it:adj[currnode]){
                int thisnode = it.first;//to
                int thiscost = it.second;//cost
                int newcost = thiscost + currcost;
                if(newcost < dist[thisnode] && currstops <= k){
                    dist[thisnode] = newcost;
                    q.push({currstops+1,{thisnode,newcost}});
                }
            }
        }
        if(dist[dst] == 1e9)return -1;
        return dist[dst];


    }
};