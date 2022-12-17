class Solution {
public:
    int solve(string op,int x,int y)
    {
        if(op=="+")return x+y;
        if(op=="-")return x-y;
        if(op=="*")return long(x)*long(y);
        if(op=="/")return x/y;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int y=st.top();
                st.pop();
                int x=st.top();
                st.pop();
                st.push(solve(tokens[i],x,y));
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
        
    }
};