class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        vector<int> target(128, 0);
        for (char c : t) target[c]++;

        int remaining = t.length();
        int left = 0, minStart = 0, minLen = INT_MAX;

        for (int right = 0; right < s.length(); right++) {
            // Only decrement remaining if the character is genuinely required
            if (target[s[right]] > 0) {
                remaining--;
            }
            target[s[right]]--;

            // When the window is valid, record and shrink from the left
            while (remaining == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // If removing s[left] causes it to be deficit, we need it again
                if (target[s[left]] == 0) {
                    remaining++;
                }
                target[s[left]]++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};