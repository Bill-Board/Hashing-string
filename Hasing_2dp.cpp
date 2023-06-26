//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
const int N=200005;
ll MOD= 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }





//struct hashing{
//   int n,b,mod;
//   string s;
//   vector<int> base,hash;
//
//   hashing(){}
//
//   void build(string s1,int b1, int mod1){
//      s = s1; b = b1; mod = mod1; n = s.size(); base.resize(n); hash.resize(n);
//
//      base[0] = 1;
//      for(int i = 1;i < n; i++)
//         base[i] = 1ll*base[i-1]*b % mod;
//
//      int h = 0;
//      for(int i= 0 ;i < n; i++){
//         h = (1ll*h*b + int(s[i])) % mod;
//         hash[i] = h;
//      }
//   }
//
//   int string_hashing(){ return hash[n-1]; }
//   int substring_hashing(int l, int r){ return (l==0)? hash[r] : (hash[r] - (1ll*hash[l-1]*base[r-l+1])%mod + mod) % mod; }
//};



ll dp[N], pow_[N];
ll dp1[N], pow_1[N];

ll power = 157; /// 157
ll power1 = 167; /// 167

pii hashing(string s){
    int n = s.size();

    pow_[0]=1;
    pow_1[0]=1;

    for(int i = 1; i<=n; i++){
        ll val = s[i-1];
        //dp[i] = modAdd(val, modMul(dp[i-1] , power));
        //pow_[i] = modMul(pow_[i-1] , power);
        dp[i] = (val +  dp[i-1] * power) % MOD;
        pow_[i] = (power * pow_[i-1]) % MOD;

        //dp1[i] = modAdd(val, modMul(dp1[i-1] , power1));
        //pow_1[i] = modMul(pow_1[i-1] , power1);
        dp1[i] = (val +  dp1[i-1] * power1) % MOD;
        pow_1[i] = (power1 * pow_1[i-1]) % MOD;
    }
    return {dp[n], dp1[n]};
}

pii get_hash(string t){
    int n = t.size();
    ll cr_h = 0, cr_h1 = 0;
    for(int i = 1; i<=n; i++){
        ll val = t[i-1];
        cr_h = modAdd(val, modMul(cr_h , power));
        cr_h1 = modAdd(val, modMul(cr_h1, power1));
    }
    return {cr_h,cr_h1};

}

pii gethas_sub(int l, int r){
    //ll ans = modSub(dp[r], modMul(pow_[r - l + 1] , dp[l-1]));
    //ll ans1 = modSub(dp1[r], modMul(pow_1[r - l + 1] , dp1[l-1]));
    ll ans = ((dp[r] - dp[l-1] * pow_[r-l+1])%MOD + MOD ) %MOD;
    ll ans1 = ((dp1[r] - dp1[l-1] * pow_1[r-l+1])%MOD + MOD ) %MOD;
    return {ans,ans1};
}




void solve(int tc)
{
    string s; cin >> s;
    pii a = hashing(s);
    cout << a.first << " " << a.second << '\n';
    while(true){
        string t; cin >> t;
        int l, r; cin >> l >> r;
        pii a = gethas_sub(l, r), b = get_hash(t);
        cout << b.first << " " << a.first << '\n';
        cout << b.second << " " << a.second << '\n';
    }
}



signed main()
{
    int test_case=1;
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
