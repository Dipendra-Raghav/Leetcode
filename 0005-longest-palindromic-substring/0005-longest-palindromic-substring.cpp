class Solution {
public:

    pair<int,int> chkOdd(string s,int i,int j)
    {
        
        int ans=0;
        if(i<0 || j>s.size() )return {i+1,j-1};
        while(i>=0 && j<s.size())
        {
            if(s[i]==s[j])
            {
                ans+=2;
                i--;
                j++;
            }
            else
                break;

        }
        return {i+1,j-1};
    }
    pair<int,int> chkEven(string s,int i,int j)
    {
        
        int ans=0;
        if(i<0 || j>s.size() )return {i+1,j-1};
        while(i>=0 && j<s.size())
        {
            if(s[i]==s[j])
            {
                ans+=2;
                i--;
                j++;
            }
            else
                break;

        }
        return {i+1,j-1};
    }
    string longestPalindrome(string s) {
      
        pair<int,int> ans;
        int mx=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            pair<int,int> p=chkOdd(s,i-1,i+1);
           
            pair<int,int> q={0,0};
            
            if(i+1<s.size()&&s[i+1]==s[i])
            {
                q=chkEven(s,i-1,i+2);
               
            }
            
            int oddLength = (p.second - p.first)+1;
            int evenLength = (q.second - q.first)+1;
            if(mx<max(oddLength,evenLength))
            {
                mx=max(oddLength,evenLength);
                if(oddLength>evenLength)
                {
                    ans.first= p.first;
                    ans.second =p.second;
                    
                }
                else
                {
                    ans.first= q.first;
                    ans.second =q.second;
                }
            
            }
           
        }
        int i=ans.first;
        int j=ans.second;
        string str="";
        for(int k=i;k<=j;k++)
            str+=s[k];
        
        return str;
        
    }
};