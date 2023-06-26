//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
inline void normal(ll &a, ll MOD) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a,MOD), normal(b,MOD); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a,MOD), normal(b,MOD); return (a+b)%MOD; }
inline ll modSub(ll a, ll b, ll MOD) { a %= MOD, b %= MOD; normal(a,MOD), normal(b,MOD); a -= b; normal(a,MOD); return a; }
inline ll modPow(ll b, ll p, ll MOD) { ll r = 1; while(p) { if(p&1) r = modMul(r, b,MOD); b = modMul(b, b,MOD); p >>= 1; } return r; }
inline ll modInverse(ll a, ll MOD) { return modPow(a, MOD-2,MOD); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b, ll MOD) { return modMul(a, modInverse(b, MOD),MOD); }




ll get_hash(string s, ll p, ll mod){
    ll power = p, cr_h = 0;
    for(auto i: s){
        ll val = i - 'A' + 1;
        cr_h = modAdd(cr_h, modMul(val, power, mod), mod);
        power = modMul(power, p, mod);
    }
    return cr_h;
}

void solve(int tc)
{
    string s; cin >> s;
    ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    int n = s.size();
    cout << get_hash(s, 31ll, mod1) << " " << get_hash(s, 37ll, mod2) << '\n';
}



signed main()
{
    int test_case=1;
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
