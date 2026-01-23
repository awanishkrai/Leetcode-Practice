class Solution {
public:
    string reverseWords(string s) {
        vector<string>h;
        string k="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && k.length()>0){
                h.push_back(k);
                k="";
            }
            else if(s[i]!=' '){
                k+=s[i];
            }
        }
        if(k.length()!=0){
            h.push_back(k);
        }
        int len=h.size();
        s="";
        for(int i=len-1;i>0;i--){
            s+=h[i];
            s+=' ';
        }
        s+=h[0];
        return s;
    }
};