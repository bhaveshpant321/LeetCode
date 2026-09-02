class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Point to remember: The values are positive, so the product of a subarray can only increase upon extension (or stay the same), not decrease

        if(k<=1) return 0;
        int n= nums.size(), left=0,  product=1, ans=0;

        for(int right=0; right<n; right++){
            product*= nums[right];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            ans+= right-left+1; // Why?: 
        }
        return ans;
    }
};