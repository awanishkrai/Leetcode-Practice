class Solution {
public:
int dc(int i,vector<int>& cookies,vector<int>&child){
    int result=INT_MAX;
   if(i==cookies.size()){
        int n=*min_element(child.begin(),child.end());
        int m=*max_element(child.begin(),child.end());
        return m;
   }
   
   for(int j=0;j<child.size();j++){
    child[j]+=cookies[i];
    result=min(result,dc(i+1,cookies,child));
    child[j]-=cookies[i];
   }
   return result;

}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        return dc(0,cookies,child);
    }
};