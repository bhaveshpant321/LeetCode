class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size(); 
        // element can appear atmost 2 times
        int ptr= 2; // first two elements are awlays valid

        for(int i=2; i<nums.size(); i++){
            if(nums[i]!= nums[ptr-2]) nums[ptr++]= nums[i]; // we need to check against the updated value
        }
        return ptr;
    }
};