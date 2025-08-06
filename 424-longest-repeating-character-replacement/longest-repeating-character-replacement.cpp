class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int maxFreq = 0, maxLen = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);
            if ((i - left + 1) - maxFreq <= k) {
                maxLen = max(maxLen, (i - left + 1));
            } else {
                maxFreq = 0; // dunno why
                mp[s[left]]--;
                left++;
            }
        }
        return maxLen;
    }
};