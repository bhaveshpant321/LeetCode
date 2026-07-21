class Solution {
public:
    int uniquePaths(int m, int n) {
        // Combinatorics solution: (m+n-2)!/(m-1)!(n-1)!
        // Optimal solution: DP: Num ways to reach the bottom: Either top or left
        
        vector<int> res(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                res[j]+= res[j-1];
            }
        }
        return res[n-1];
    }
};