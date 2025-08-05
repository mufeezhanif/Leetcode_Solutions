class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int len1 = s1.size(), len2 = s2.size();
        vector<int> c1(26, 0), c2(26, 0);

        for (char ch : s1) {
            c1[ch - 'a']++;
        }
        for (int i = 0; i < len2; ++i) {
            c2[s2[i] - 'a']++;
            if (i >= len1) {
                c2[s2[i - len1]-'a']--;
            }
            if (c1 == c2)
                return true;
        }
        return false;
    }
};