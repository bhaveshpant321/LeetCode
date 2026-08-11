class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // possible moves: Either from up or left
        // 1D solution: take the first column and take prefix sum
        int m= grid.size(), n= grid[0].size();
        vector<int> curr(n, 0);
        int prev=0;
        for(int i=0; i<n; i++){
            curr[i]= prev+grid[0][i];
            prev= curr[i];
        }

        // Traverse from row 2
        for(int i=1; i<m; i++){
            curr[0]+=grid[i][0];
            for(int j=1; j<n; j++){
                curr[j]= grid[i][j]+ min(curr[j], curr[j-1]);
            }
        }
        return curr[n-1];
    }
};