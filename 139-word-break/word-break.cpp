class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // try every index and see if it's possible to make from all the possible 
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0]= true;
        for(int i=1; i<= s.size(); i++){
            for(int j=i-1; j>=0; j--){   // can definitely go forward as well, but moving backwards has real life optimization advantages, as we'll be first checking smaller substrings in dict and dicts in real life would normally have strings of small size. 
            // Optimization: While inserting in the unordered set, we can also keep note of the max len of the substring and use that as the delimiter instead of 0 for less loop lookups

                if(dp[j] && dict.count(s.substr(j, i-j))){
                    dp[i]= true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};