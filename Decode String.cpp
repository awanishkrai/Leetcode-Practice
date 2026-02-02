class Solution {
public:
string decode(string s,int &i){
   string result="";
   while(i<s.size()&& s[i]!=']'){
    
    if(isdigit(s[i])){
        int nu=0;
        while(isdigit(s[i])){
            nu=nu*10+(s[i]-'0');
            i++;
        }
        i++;
        string inner=(decode(s,i));
        i++;
        while(nu--){
            result+=inner;
        }

    }
    else{
        result+=s[i];
        i++;
    }
    
   }
    return result;
}
    string decodeString(string s) {
        
        int i=0;
        return decode(s,i);
    }
};