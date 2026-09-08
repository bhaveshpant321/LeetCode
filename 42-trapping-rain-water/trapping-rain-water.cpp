class Solution {
public:
    int trap(vector<int>& height) {
        // for each index i, the max water that can be held there is equivalent to min of max height from both left and right- hieght of the block itself
        // Trapped rainwater= sum of all
        int left=0, right= height.size()-1;
        int leftMax= height[left], rightMax= height[right];
        int water=0;

        while(left<right){
            if(leftMax< rightMax){
                left++;
                leftMax= max(leftMax, height[left]);
                water+=leftMax-height[left];
            }else{
                right--;
                rightMax= max(rightMax, height[right]);
                water+=rightMax- height[right];
            }
        }
        return water;
    }
};