class Solution {
public:
    int maxVowels(string s, int k) {
        int maxNum = 0;
        int count = 0;
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        for (int i = 0; i < s.size(); ++i) {
            if (st.count(s[i])) {
                count++;
                maxNum = (maxNum > count) ? maxNum : count;
            }
            if (i >= k - 1) {
                if (st.count(s[i - k + 1])) {
                    count--;
                }
            }
        }
        return maxNum;
    }
};