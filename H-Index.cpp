class Solution {
public:
    int hIndex(vector<int>& citations) {
        map<int,int> mp;
        int n = citations.size();
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n; j++){
                if(citations[i] >= j){
                    mp[j]++;
                }
            }
        }
        
        for(int i = n; i >= 1; i--){
            if(mp[i] >= i){
                return i;
            }
        }
        return 0;
    }
};
