class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // DP approach: LIS
        
        // find longest consecutive interval
        // sort by end times
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){return a[1]< b[1];});
        /*
        PS: how to identify whether to sort by start or end time:
        Look at the core objective of the question: maximizing the number of processed items/intervals requires sorting by end time, while combining, grouping, or modifying overlapping intervals requires sorting by start time
        */
        int ans= 1;
        int prev= pairs[0][1];

        for(int i=1; i<pairs.size(); i++){
            if(pairs[i][0]> prev){
                ans++;
                prev= pairs[i][1];
            }
        }
        return ans;
    }
};