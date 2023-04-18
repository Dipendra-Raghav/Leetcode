class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        bool flag=true;
        int n=word1.size();
        int m=word2.size();
        int k=n+m;
        int p=0;
        int q=0;
        for(int i=0;i<k;i++)
        {
            if(flag)
            {
                ans+=word1[p];
                p++;
                flag=!flag;
            }
            
            else
            {
                ans+=word2[q];
                q++;
                flag=!flag;
            }
            if(p>=word1.size())
            {
                flag=false;
              
            }
            if(q>=word2.size()) 
            {
                flag=true;
               
            }
        }
        return ans;
        
        
    }
};