class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        unordered_map<char, int> mp;
        int maxCount = 0, count = 0, left = 0;
        for (int right = 0; right < s.size(); ++right) {
            mp[s[right]]++;
            while (mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }

            maxCount = max(maxCount, (right - left + 1));
        }
        return maxCount;
    }
};