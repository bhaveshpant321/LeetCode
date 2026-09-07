class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adj list u: v, dist
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto& t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, node
        pq.push({0, k});

        vector<int> dist(n+1, 1e9);
        // dist[0]= 0; // unreachable node, do not count
        dist[k]=0;
        
        while(!pq.empty()){
            auto [du, u]= pq.top(); pq.pop();
            if(du> dist[u]) continue;
            for(auto& [v, d]: adj[u]){
                if(dist[v]> du+d){
                    dist[v]= du+d;
                    pq.push({dist[v], v});
                }
            }
        }

        // min time would be max distance
        int maxi= *max_element(dist.begin()+1, dist.end());
        return maxi <1e9? maxi: -1; 
    }
};