class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans = "";
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else
                    continue;
            }
            ans += c;
        }
        if (st.empty())
            return ans;
        for (int i = ans.size() - 1; i >= 0 && !st.empty(); --i) {
            if (ans[i] != '(')
                continue;
            ans.erase(i, 1);
            st.pop();
        }
        return ans;
    }
};