class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto it:wordList)
        {
            st.insert(it);
        }
        queue <pair<string,int>> qe;
        qe.push({beginWord,1});
        st.erase(beginWord);
        while(!qe.empty())
        {
            string s=qe.front().first;
            int len=qe.front().second;
            if(s == endWord)
            return len;
            qe.pop();
            for(int i=0;i<s.length();i++)
            {   char orig=s[i];
                for(char ch='a';ch<='z';ch++)
                {
                   s[i]=ch;
                   if(st.find(s) != st.end())
                   {
                    st.erase(s);
                    qe.push({s,len+1});
                   }
                }
                s[i]=orig;
            }
        }
        return 0;
    }
};