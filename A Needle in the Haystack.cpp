//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int N=10000005;
ll MOD= 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

string t, s;
ll dp[N+10], pow_[N+10];
ll dp1[N+10], pow_1[N+10];

void hashing(){
    int n = s.size();
    ll power = 31;
    pow_[0]=1;

    ll power1 = 37;
    pow_1[0]=1;

    for(int i = 1; i<=n; i++){
        ll val = s[i-1] - 'a' + 1;
        dp[i] = modAdd(val, modMul(dp[i-1] , power));
        pow_[i] = modMul(pow_[i-1] , power);

        dp1[i] = modAdd(val, modMul(dp1[i-1] , power1));
        pow_1[i] = modMul(pow_1[i-1] , power1);
    }
}

ll get_hash(ll power){
    int n = t.size();
    ll cr_h = 0;
    for(int i = 1; i<=n; i++){
        ll val = t[i-1] - 'a' + 1;
        cr_h = modAdd(val, modMul(cr_h , power));
    }
    return cr_h;
}

ll alasub(int l, int r){
    ll ans = modSub(dp[r], modMul(pow_[r - l + 1] , dp[l-1]));
    return ans;
}

ll alasub1(int l, int r){
    ll ans = modSub(dp1[r], modMul(pow_1[r - l + 1] , dp1[l-1]));
    return ans;
}


void solve(int tc)
{
    int n;
    while(cin >> n >> t >> s){
        hashing();
        pii a = {get_hash(31ll), get_hash(37ll)};
        int sz = s.size();
        for(int i = 0, j = n-1; j<sz; i++,j++){
            pii b = {alasub(i+1,j+1), alasub1(i+1,j+1)};
            if(a == b)cout << i << '\n';
        }cout << '\n';
    }
}



signed main()
{
    int test_case=1;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...

