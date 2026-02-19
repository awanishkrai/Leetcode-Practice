//it supports 2 operations efficiently
//1 find
//2 Union
// time complaxity -O(log n)

//union by size->smaller to larger
//path compression technique ensure  find operartion in O(1);
class dsu{
    int n;
    vector<int>par(n);
    vector<int>size(n);
    dsu(int n){
        this->n=n;
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int i){
        if(parent[i]==i)return i;
        //path compression 
        return parent[x]= find(parent[x]);
    }

}