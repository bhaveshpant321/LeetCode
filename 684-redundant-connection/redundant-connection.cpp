class Solution {
    vector<int> parent;

    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]= find(parent[i]);
    }
    bool unite(int u ,int v){
        int root_u= find(u);
        int root_v= find(v);
        if(root_u==root_v) return true;
        parent[root_u]= root_v;
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // DSU to find the redundant edge (when root of u and v are the same)
        int n= edges.size();
        parent.resize(n+1); // 1 indexed
        iota(parent.begin(), parent.end(), 0);

        for(const auto& edge: edges){
            int u= edge[0], v= edge[1];
            if(unite(u, v)){
                return edge;
            }
        }
        return {};
    }
};