class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // At max two elements can appear more than n/3 times
        // Optimal solution: Voting algo for two elements
        // Two elements, two counts: count 1 is 0, set current as element 1 and count 1 as 1, else if count 2 0, set current as element 2 and count 2 as 1
        vector<int> ans;
        if(nums.size()<=1) return nums;
        int el1=-1, el2= -1, c1=0, c2=0;

        for(int ele: nums){
            if(ele==el1) c1++;
            else if(ele==el2) c2++;
            else if(c1==0){ el1= ele; c1++;}
            else if(c2==0){ el2= ele; c2++;}
            else{ c1--; c2--;}
        }

        // Verify
        c1=0; c2=0;
        for(int ele: nums){
            if(ele==el1) c1++;
            else if(ele==el2) c2++;
        }

        if(c1> nums.size()/3) ans.push_back(el1);
        if(c2> nums.size()/3) ans.push_back(el2);

        return ans;
    }
};