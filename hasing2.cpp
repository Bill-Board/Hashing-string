//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
ll MOD= 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll dp[N], inv[N];

ll hashing(string s){
    int n = s.size();
    ll power = 31, power_pro = 1;
    inv[0]=1;
    for(int i = 1; i<=n; i++){
        ll val = s[i-1] - 'a' + 1;

        power_pro = modMul(power_pro, power); /// eta age dile inv[l-1] hbe, otherwise inv[l] hbe
        inv[i] = modPow(power_pro, MOD-2);
        dp[i] = modAdd(dp[i-1], modMul(val , power_pro));
    }
    return dp[n];
}

ll alabu(string s){
    int n = s.size();
    ll power = 31, power_pro = 1, cr_h = 0;
    for(int i = 1; i<=n; i++){
        ll val = s[i-1] - 'a' + 1;
        power_pro = modMul(power_pro, power);
        cr_h = modAdd(cr_h, modMul(val , power_pro));
    }
    return cr_h;
}
ll alasub(int l, int r){
    ll ans = modMul(modSub(dp[r] , dp[l-1]), inv[l-1]);
    return ans;
}



void solve(int tc)
{
    string s; cin >> s;
    cout << hashing(s) << '\n';
    while(true){
        string t; cin >> t;
        int l, r; cin >> l >> r;
        cout << alabu(t) << " " << alasub(l, r) << '\n';
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
