class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int count = 0;
        int ans = 0;
        for (auto it : s) {
            if (it == '(') {
                if (count == 1) {
                    if (!st.empty()) {
                        ans++;
                        st.pop();
                    } else {
                        ans = ans + 2;
                    }
                    count = 0;
                }
                st.push('(');
            } else {
                count++;
                if (st.empty()) {
                    if (count == 2) {
                        ans++;
                        count = 0;
                    }
                } else {
                    if (count == 2) {
                        st.pop();
                        count = 0;
                    }
                }
            }
        }
        if (count == 1) {
                    if (!st.empty()) {
                        ans++;
                        st.pop();
                    } else {
                        ans = ans + 2;
                    }
                    count = 0;
                }
     ans+=2*st.size();
     return ans;
    }
};