class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left=0, maxCount=0, maxLen=0;

        for(int right=0; right<s.size(); right++){
            // Add curr
            freq[s[right]-'A']++;
            // max freq in the window
            maxCount= max(maxCount, freq[s[right]-'A']);
            // Number of replacements required
            while((right-left+1)-maxCount> k){
                freq[s[left]-'A']--;
                left++;
            }
            // Update max window length
            maxLen= max(maxLen, right-left+1);
        }
        return maxLen;
    }
};