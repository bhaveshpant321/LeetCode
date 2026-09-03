class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // generating all pairs take O(m*n) time, instead use min heap to extract only k elements
        // Initialization: push first pair of elements (nums1[i], nums2[0]) along with indices for first min(k, nums1.size()) elements into min heap
        // Extraction: pop> add to list> push nums1[i], nums2[j+1] into the heap
        // Repeat until k extractions/empty heap

        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        for(int i=0; i< nums1.size(); i++){
            minHeap.push({nums1[i]+ nums2[0], {i,0}});
        }

        while(k--){
            auto [sum, index]= minHeap.top();
            int i= index.first, j= index.second;
            ans.push_back({nums1[i], nums2[j]});
            minHeap.pop();
            if(j+1< nums2.size())   minHeap.push({nums1[i]+ nums2[j+1], {i, j+1}});
        }
        return ans;
    }
};