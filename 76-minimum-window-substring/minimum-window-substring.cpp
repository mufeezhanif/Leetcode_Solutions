class Solution {
public:
    string minWindow(string s, string t) {
        int count = 0, minLen = s.size() + 78, startingInd = -1, left = 0,
            right = 0;

        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }
        for (; right < s.size(); ++right) {
            if (mp[s[right]] > 0) {
                count++;
            }
            mp[s[right]]--;
            while (count == t.size()) {
                if ((right - left + 1) < minLen) {
                    minLen = (right - left + 1);
                    startingInd = left;
                }
                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    count--;
                }
                left++;
            }
        }
        return (startingInd == -1) ? ""
                                   : s.substr(startingInd, minLen);
    }
};