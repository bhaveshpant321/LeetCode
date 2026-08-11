class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& a) {
        // Two approaches: Kruskals (DSU) and Prims (greedy/ min heap)
        // Using prims
        int n= a.size(), ans=0;
        vector<int> d(n, 1e9), vis(n);
        d[0]=0;

        for(int i=0; i<n; i++){
            int u=-1;
            
            for(int j=0; j<n; j++) if(!vis[j] && (u==-1 || d[j]<d[u])) u=j;
            
            vis[u]=1;
            ans+=d[u];

            for(int v=0; v<n; v++) if(!vis[v]) d[v]= min(d[v], abs(a[u][0]-a[v][0])+ abs(a[u][1]-a[v][1]));
        }
        return ans;
    }
};
/*
Kruskal's:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) with Path Compression and Union by Rank
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Union by rank
            if (rank[root_i] < rank[root_j]) {
                swap(root_i, root_j);
            }
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j]) {
                rank[root_i]++;
            }
            return true; // Successfully united (no cycle)
        }
        return false; // Already in the same component (cycle detected)
    }
};

struct Edge {
    int u, v, weight;
    
    // Sort edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // O(E log E)

    DSU dsu(V);
    int mst_weight = 0;
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.weight;
            edges_count++;
            if (edges_count == V - 1) break; // MST complete
        }
    }

    return (edges_count == V - 1) ? mst_weight : -1; // -1 if disconnected
}
*/