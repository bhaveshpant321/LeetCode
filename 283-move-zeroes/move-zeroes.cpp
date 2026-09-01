class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;    // pointer for placing next non-zero element
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                if(i!=j) nums[j]= nums[i];
                j++;
            }
        }
        while(j<nums.size()){
            nums[j++]=0;
        }
    }
};