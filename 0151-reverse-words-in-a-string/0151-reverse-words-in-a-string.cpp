class Solution {
public:
    string reverseWords(string s) {
        string str="";
        stack<string> ans;
        bool flag=false;
        bool start=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' && start==false)continue;
            if(s[i]==' ')
            {
                ans.push(str);
                cout<<str<<endl;
                str="";
                start=false;
                flag=false;
                continue;
            }
            str+=s[i];
            start=true;
            flag=true;
        }
        cout<<flag<<" ";
        if(flag)ans.push(str);
        string res="";
        while(!ans.empty())
        {
            res+=ans.top();
            ans.pop();
            if(!ans.empty())res+=" ";
            
        }
        return res;
            
        
    }
};