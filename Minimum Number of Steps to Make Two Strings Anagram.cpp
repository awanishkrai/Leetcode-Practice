class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp1;
        map<char,int>mp2;
        for(char c:s){
            mp1[c]++;
        }
        for(char c:t){
            mp2[c]++;
        }
        int k=0;
        for(auto i:mp1){
            if(i.second>mp2[i.first]){
            int d=i.second-mp2[i.first];
            k+=d;
            }
        }
        return k;
    }
};