class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> m;
        m['(']=')';
        m['{']='}';
        m['[']=']';
        
        for(int i=0;i<s.size();i++)
        {
            auto it=m.find(s[i]);
            if(it!=m.end())
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()==false && s[i]==m[st.top()])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
        
    }
};