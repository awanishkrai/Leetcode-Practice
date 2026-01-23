class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_str=0;
        int count=0;
        int n=s.length();
        map<char,int>mp;
        int l=0;;
        int r=0;
        while(r<n){
            mp[s[r]]++;
            count++;
            if(mp[s[r]]==1){
                max_str=max(count,max_str);
                
            }
            else{
                while(mp[s[r]]>1){
                    mp[s[l]]--;
                    l++;
                    count--;
                }
            }
            r++;
        }
        return max_str;
    
    }
};