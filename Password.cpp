//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
const int N=1000005;
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
string s;
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


pii gethas_sub(int l, int r){
    ll ans = modSub(dp[r], modMul(pow_[r - l + 1] , dp[l-1]));
    ll ans1 = modSub(dp1[r], modMul(pow_1[r - l + 1] , dp1[l-1]));
    return {ans,ans1};
}

bool alabu(int mid){
    int n = s.size();
    for(int i = 2; i<=(n-mid); i++)
        if(gethas_sub(1, mid) == gethas_sub(i,i+mid-1))
            return true;
    return false;
}


void solve(int tc)
{
    cin >> s;
    int n = s.size();
    hashing();
    vector<int> a;
    for(int i = 1; i<n; i++){
        if(gethas_sub(1,i) == gethas_sub(n-i+1,n))
            a.push_back(i);
    }
    if(a.empty()){
        cout << "Just a legend\n";
        return;
    }
    //for(auto i: a)cout << i << " "; cout << '\n';
    int l = 0, r = a.size()-1, ans = -1;
    while(l<=r){
        int mid = (l + r)/2;
        //cout << mid << '\n';
        if(alabu(a[mid]))
            l = mid+1, ans  = mid;
        else
            r = mid-1;
    }
    //cout << l << " " << r << " " << a[ans] << '\n';
    if(ans == -1)
        cout << "Just a legend\n";
    else
        cout << s.substr(0,a[ans]) << '\n';
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
