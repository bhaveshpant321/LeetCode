class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Approach: sorting and two pointer with duplicate removal. 
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        int end= nums.size();

        for(int i=0; i+2<end; i++){
            // Pigeonhole: If current number is positive, then following numbers will also be positive, hence sum 0 is not possible
            if(nums[i]>0) return solution;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left= i+1, right= end-1, target= 0-nums[i];
            
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    solution.push_back({nums[i], nums[left], nums[right]});
                    // Only remove dupes once found
                    while(left<right && nums[left]== nums[left+1]) left++;
                    while(left<right && nums[right]== nums[right-1]) right--;    
                    left++;
                    right--;
                }
            }
        }
        return solution;
    }
};