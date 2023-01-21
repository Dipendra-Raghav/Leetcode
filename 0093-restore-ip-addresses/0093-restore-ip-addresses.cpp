class Solution {
public:
    vector<string> ans;
    string str="";
    void solve(string s, int i,int k)
    {
        //base case
        if(k==4 && i>=s.size())
        {
            str.pop_back();
            ans.push_back(str);
            str +='.';
        }
        if(k>4)return;
        
        
        //take 1
         if(i<s.size()){

            str+=s[i];
            str+=".";
            solve(s,i+1,k+1);
        
            str.pop_back();
            str.pop_back();
    
         }
        //take 2
        if(i+1<s.size() && s[i]!='0')
        {
            str+=s[i];
            str+=s[i+1];
            str+=".";
            solve(s,i+2,k+1);
            str.pop_back();
            str.pop_back();
            str.pop_back();
        }
        //take 3
        if(i+2<s.size() && s[i]!='0' && stoi(s.substr(i, 3)) <= 255)
        {
            str+=s[i];
            str+=s[i+1];
            str+=s[i+2];
            str+=".";
            solve(s,i+3,k+1);
            str.pop_back();
            str.pop_back();
            str.pop_back();
            str.pop_back();
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
       solve(s,0,0);
       return ans; 
    }
};