class Solution {
public:
bool chk(string& str, string& s) {
    for (char c : s) {
        
        if (str.find(c) != string::npos) {
            return false;  
        }
        str+=c;
        
    }
    return true;  
}
    int solve(vector<string>& arr,string s,int i)
    {
        //base condn
        if(i>=arr.size())return 0;
        //include
        int inc=0,excl=0;
        excl=solve(arr,s,i+1);
        if(chk(s,arr[i]))
        {
            s+=arr[i];
            inc=arr[i].size()+solve(arr,s,i+1);
        }
        
        
        return max(inc,excl);
    }
    int maxLength(vector<string>& arr) {
        return solve(arr,"",0);
        
    }
};