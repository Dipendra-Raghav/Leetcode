class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool flag=false;
        bool flagg=false;
        
        if(word.size()==1)return true;
        for(int i=1;i<word.size();i++)
        {
            if(word[i]!=toupper(word[i]))
            {
                
                flag=true;
            }
            else
            {
                flagg=true;
            }
            if(flag==true && flagg==true)return false;
            
        }
        
        if(word[0]!=toupper(word[0]) && flagg==true)return false;
        else return true;
        
    }
};