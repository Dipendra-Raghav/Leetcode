class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int c=1;
        string p=a;
        while(a.size() < b.size())
        {    
            a += p;
            c++;
        }
        if(a.find(b)!=-1)return c;
          a += p;
        c++;
        if(a.find(b)!=-1)return c;
        else
            return -1;
        
        
    }
};