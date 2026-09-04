class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int i=0;
        // push all non overlapping before given new interval
        while(i<intervals.size() && intervals[i][1]< newInterval[0]){
            merged.push_back(intervals[i]);
            i++;
        }
        // merging overlapping intervals
        while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
            newInterval[0]= min(newInterval[0], intervals[i][0]);
            newInterval[1]= max(newInterval[1], intervals[i][1]);
            i++; 
        }
        merged.push_back(newInterval);

        // Inserting the remaining non overlapping intervals
        while(i<intervals.size()){
            merged.push_back(intervals[i]);
            i++;
        }
        return merged;
    }

};