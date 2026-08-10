class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map solution
        unordered_map<int, int> map;    // target-val, index
        for(int i=0; i<nums.size(); i++){
            if(!map.count(nums[i])){
                map.insert({target-nums[i], i});
            }else{
                return {map[nums[i]], i};
            }
        }
        return {-1, -1};
    }
};