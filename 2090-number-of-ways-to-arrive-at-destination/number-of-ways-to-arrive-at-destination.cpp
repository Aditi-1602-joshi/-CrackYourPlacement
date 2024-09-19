class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        //create an adjacency list
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX), ways(n,0);

        ways[0] = 1;
        dist[0] = 0;

        pq.push({0,0});
        //dist,node
        long long mod =(1e9+7);
        while(!pq.empty()){
            int node = pq.top().second;
            long long dis = pq.top().first;

            pq.pop();

            for(auto it: adj[node]){
                int adjnode = it.first;
                long long adjwt = it.second;

                long long newwt = adjwt + dis;
                
                if(newwt < dist[adjnode]){
                    pq.push({newwt,adjnode});
                    dist[adjnode] = newwt;
                    ways[adjnode] = ways[node];
                }
                else if(newwt == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};