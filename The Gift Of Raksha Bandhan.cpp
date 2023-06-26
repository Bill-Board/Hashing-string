//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
const int N=5000005;
ll MOD= 1e9+7;

ll dp[N], pow_[N];
ll power = 157, power1 = 167;
string s;
void hashing(){
    int n = s.size();

    pow_[0]=1;

    for(int i = 1; i<=n; i++){
        ll val = s[i-1] - 'a' + 1;
        dp[i] = (val +  dp[i-1] * power) % MOD;
        pow_[i] = (power * pow_[i-1]) % MOD;
    }
}



ll gethas_sub(int l, int r){
    ll ans = ((dp[r] - dp[l-1] * pow_[r-l+1])%MOD + MOD)%MOD;
    return ans;
}




void solve(int tc)
{
    int q;
    cin >> s >> q;
    int n = s.size();
    hashing();

    while(q--){
        int k;
        cin >> k;
        int l = 1, r = min(k, n- k), ans = 0;
        while(l<=r){
            int mid  = (l + r) >> 1;
            if(gethas_sub(1, mid) == gethas_sub(k+1, k + mid)){
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid - 1;
        }
        cout << ans << '\n';
    }
}


signed main()
{
    int test_case=1;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //scanf("%d", &test_case);
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
