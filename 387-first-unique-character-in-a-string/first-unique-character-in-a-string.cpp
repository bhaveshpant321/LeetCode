class Solution {
public:
    int firstUniqChar(string s) {
        // Two pass approach: count frequencies in pass 1 and find the first element in pass 2
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]-'a']==1) return i;
        }
        return -1;
        
        // Possible single pass approach? Single pass possible? If we used a data structure that allowed O(1) insertion and deletion, we could use that along with a set: append, if found, delete
        // Possible data structure: list/forward_list with unordered map (stores the element and list iterator): mimics LRU cache
        // Although while average case complexity remains similar, this approach is more computationally expensive
        /*
        #include <string>
        #include <list>
        #include <unordered_map>

        class Solution {
        public:
            int firstUniqChar(std::string s) {
            // Pair stores: {character, string_index}
            std::list<std::pair<char, int>> unique_chars;

            // Maps character to its iterator in the list. 
            // If frequency > 1, we map it to unique_chars.end() as a sentinel marker.
            std::unordered_map<char, std::list<std::pair<char, int>>::iterator> char_map;

            for (int i = 0; i < s.length(); i++) {
                char c = s[i];
                
                if (char_map.find(c) == char_map.end()) {
                    // First time seeing the character: push to list and store iterator
                    unique_chars.push_back({c, i});
                    char_map[c] = --unique_chars.end();
                } else if (char_map[c] != unique_chars.end()) {
                    // Second time seeing it: erase from list in O(1) using the iterator
                    unique_chars.erase(char_map[c]);
                    // Mark as duplicated so we ignore it if it appears a 3rd or 4th time
                    char_map[c] = unique_chars.end();
                }
                // If it's a 3rd+ time seeing it, char_map[c] is already unique_chars.end(), we do nothing
            }

            // The first element remaining in the list is our first unique character
            return unique_chars.empty() ? -1 : unique_chars.front().second;
            }
        };
        */
    }
};