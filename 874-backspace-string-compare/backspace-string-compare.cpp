class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        int len1 = s.size(), len2 = t.size();
        int i = 0, j = 0;
        while (i < len1 || j < len2) {
            if (i < len1) {
                if (s[i] == '#') {
                    if (!s1.empty())
                        s1.pop();
                } else
                    s1.push(s[i]);
                ++i;
            }
            if (j < len2) {
                if (t[j] == '#') {
                    if (!s2.empty())
                        s2.pop();
                } else
                    s2.push(t[j]);
                ++j;
            }
        }
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return s1.empty() && s2.empty() ? true : false;
    }
};