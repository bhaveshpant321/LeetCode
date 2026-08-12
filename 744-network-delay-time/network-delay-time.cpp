class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Adjacency list> u : {v, weight}
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto& edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min heap (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n+1, 1e9); // 1-n

        dist[k]=0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, u]= pq.top();
            pq.pop();
        
            // Skip outdated pair (lazy deletion)
            if(d> dist[u]) continue;

            for(const auto& [v, weight]: adj[u]){
                if(dist[u]+weight< dist[v]){
                    dist[v]= dist[u]+weight;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxTime= 0;
        for(int i=1; i<=n; i++){
            if(dist[i]==1e9) return -1;
            maxTime= max(maxTime, dist[i]);
        }
        return maxTime;

    }
};