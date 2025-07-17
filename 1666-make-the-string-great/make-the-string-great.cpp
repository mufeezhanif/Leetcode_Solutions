class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty()) {
                st.push(c);
            } else if (isupper(c)) {
                if (st.top() == tolower(c))
                    st.pop();
                else {
                    st.push(c);
                }
            } else if (isupper(st.top())) {
                if (tolower(st.top()) == c)
                    st.pop();
                else
                    st.push(c);
            } else
                st.push(c);
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};