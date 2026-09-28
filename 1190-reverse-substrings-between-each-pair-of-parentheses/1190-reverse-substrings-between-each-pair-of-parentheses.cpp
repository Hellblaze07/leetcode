class Solution {
public:
    string reverseParentheses(string s) {
        stack <char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] != ')')
            st.push(s[i]);
            else {  string ans="";
                while(st.top() != '(')
                {  
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto it:ans)
                st.push(it);
            }
        }
        string ans;
       while(!st.empty())
       { ans.push_back(st.top());
       st.pop();
       }
       reverse(ans.begin(),ans.end());
     return ans;
    }
};