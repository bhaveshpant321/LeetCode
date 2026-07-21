class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Can be optimally done using Floyd's (learn the approach tho)

        int slow= nums[0], fast= nums[0];
        
        while(true){
            slow= nums[slow];
            fast= nums[nums[fast]];
            if(slow==fast) break;
        }
        int slow2= nums[0];
        while(slow!=slow2){
            slow= nums[slow];
            slow2= nums[slow2];
        }
        return slow;

        // Approach 2: Binary search: take the mid, count how many values less than mid (nlogn). Pigeonhole principle: If a number repeats itself in a continuous range 1-n, ther will be n+1 numbers (making that our search space), if numbers are n, no number is repeating
    }
};