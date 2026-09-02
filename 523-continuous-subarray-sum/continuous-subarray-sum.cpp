class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // prefix sum+ hashmap
        unordered_map<int, int> map;
        map[0]=-1;    // Why? So that we can return true when runningSum%k=0
        int runningSum=0;

        for(int i=0; i<nums.size(); i++){
            runningSum+= nums[i];
            if(k!=0) runningSum= runningSum%k;
            if(map.count(runningSum)){
                if(i- map[runningSum]>1) return true;
            }else map[runningSum]= i;
        }
        return false;
    }
};