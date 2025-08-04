class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        if(k>=s.size()) return false;
        for (int i = 0; i < s.size() - k + 1; ++i) {
            st.insert(s.substr(i, k));
        }
        if (st.size() == pow(2, k)) {
            return true;
        }
        return false;
    }
};