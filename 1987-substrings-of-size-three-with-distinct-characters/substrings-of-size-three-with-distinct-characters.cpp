class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int left = 0, right = 1;
        for (; right < s.size(); ++right) {
            if(s[left]==s[right]) left++;
            if ((right - left + 1) == 3) {
                if (s[right] != s[left] && s[right] != s[right - 1]) {
                    left++;
                    count++;
                }
                else {
                    right--;
                    left++;
                }
            }
        }
        return count;
    }
};