class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Put the numbers in a set, start checking only for valid first numbers
        // Eg in (100, 4, 200, 1, 3, 2) 1 is valid first number as 0 isn't there, but 2 isn't as 1 is there
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest=0;
        for(int n: numSet){
            if(!numSet.count(n-1)){ // found valid first
                int len=1;
                while(numSet.count(n+len)) len++;
                longest= max(longest, len);
            }
        }
        return longest;
    }
};