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

ll dp[N], pow_[N];
ll dp1[N], pow_1[N];

ll power = 157; /// 157
ll power1 = 167; /// 167
string s;
void hashing(){
    int n = s.size();

    pow_[0]=1;
    pow_1[0]=1;

    for(int i = 1; i<=n; i++){
        ll val = s[i-1];
        dp[i] = modAdd(val, modMul(dp[i-1] , power));
        pow_[i] = modMul(pow_[i-1] , power);

        dp1[i] = modAdd(val, modMul(dp1[i-1] , power1));
        pow_1[i] = modMul(pow_1[i-1] , power1);
    }
}


pii gethas_sub(int l, int r){
    ll ans = modSub(dp[r], modMul(pow_[r - l + 1] , dp[l-1]));
    ll ans1 = modSub(dp1[r], modMul(pow_1[r - l + 1] , dp1[l-1]));
    return {ans,ans1};
    //return ans;
}




void solve(int tc)
{
    int n, k;
    cin >> n >> k >> s;
    hashing();
    set<pii> p;
    for(int i = 1; i<=(n-k+1); i++)
        p.insert(gethas_sub(i, i + k -1));
    cout << p.size()  << '\n';

}



signed main()
{
    int test_case=1;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
