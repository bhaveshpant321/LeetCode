class Solution {
public:
    int maxArea(vector<int>& height) {
        // Greedy two pointers: keep a global max, greedily move from the lower height (bottleneck)
        int left= 0, right= height.size()-1, maxi= -1e9;
        while(left<right){
            int area= min(height[left], height[right])* (right-left);
            maxi= max(maxi, area);
            height[left]<height[right]? left++: right--;
        }
        return maxi;
    }
};