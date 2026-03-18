// Author: Awanish_Rai
// Template: Codeforces Competitive Programming

#include <bits/stdc++.h>
using namespace std;

// PBDS (optional, comment if not used)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Fast IO
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

// Macros
#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

// Debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// Debug print helpers
void _print(int x) {cerr << x;}
void _print(string x) {cerr << '"' << x << '"';}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(bool x) {cerr << (x ? "true" : "false");}
template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector<T> v) {cerr << "["; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "{"; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map<T, V> v) {cerr << "{"; for (auto i : v) {_print(i); cerr << " ";} cerr << "}";}

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Modular arithmetic
int mod_add(int a, int b, int m = MOD) { return ((a % m + b % m + m) % m); }
int mod_sub(int a, int b, int m = MOD) { return ((a % m - b % m + m) % m); }
int mod_mul(int a, int b, int m = MOD) { return ((a % m) * (b % m)) % m; }
int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}
int mod_inv(int a, int m = MOD) {
    return mod_pow(a, m - 2, m);
}
//vector<vector<int>>dp(2e6,vector<int>(2,-1));
// int recur(int height,int type,int n){
//     if(height==n)return 1;
//     if(dp[height][type]!=-1)return dp[height][type];
//     int way=0;
//     if(type==0){
//         way=(way+2*recur(height+1,0,n)+recur(height+1,1,n))%MOD;
//     }
//     else{
//         way=(way+4*recur(height+1,1,n)+recur(height+1,0,n))%MOD;
//     }
//     return dp[height][type]=way;
// }
// // Solve function for each test case
// void solve() {
//     int n;
//     cin >> n;
//       dp.assign(n+2, vector<int>(2,-1));
//     cout<< (recur(1,0,n)+recur(1,1,n))%MOD<<endl;
// }
// int recur(int height, int type, int n){
//     if(height > n) return 0;
//     if(height == n) return 1;
//     if(dp[height][type] != -1) return dp[height][type];

//     int way = 0;
//     if(type == 0){
//         way = (2*recur(height+1,0,n) % MOD + recur(height+1,1,n) % MOD) % MOD;
//     } else {
//         way = (4*recur(height+1,1,n) % MOD + recur(height+1,0,n) % MOD) % MOD;
//     }
//     return dp[height][type] = way;
// }

// void solve(){
//     int n; 
//     cin >> n;
//     int k=(recur(1,0,1e6) + recur(1,1,1e6)) % MOD ;
//     while(n--){
//         int a;
//         cin>>a;
//         cout<<3*dp[a-1][0]+5*dp[n-1][1]<<endl;
//     }
// }
static vector<vector<int>>dp(2e6,vector<int>(2,-1));
void solve(){
    int n;
    cin>>n;
    
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=1e6;i++){
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%MOD;
    }
    while(n--){
        int a;
        cin>>a;
    cout<<(dp[a][0]+dp[a][1])%MOD<<endl;
    }
}
// Main
int32_t main() {
    fast_io;

    int T = 1;
    //cin >> T; // Uncomment if multiple test cases

    while (T--) {
        solve();
    }

    return 0;
}
