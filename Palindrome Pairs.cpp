//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
const int N=5002;
ll MOD= 1e9+7;



ll dp[N][303], pow_[N];
ll dpu[N][303];

ll power = 37; /// 157


ll gethas_sub(int l, int r, int id){
    ll ans = ((dp[id][r] - dp[id][l-1] * pow_[r-l+1])%MOD + MOD ) %MOD;
    return ans;
}
ll gethas_subulta(int l, int r, int id){
    ll ans = ((dpu[id][r] - dpu[id][l-1] * pow_[r-l+1])%MOD + MOD ) %MOD;
    return ans;
}
bool alabu(int x, int y, int sz1, int sz2){

    if( x == y)return 0;

    if(sz1+sz2 <= 1)return 1;

    if(sz1 <= sz2 and gethas_sub(1, sz1, x) == gethas_subulta(1,sz1,y)){
        int l = sz1 +1, r  = sz2;
        if(r - l + 1 < 2)
            return 1;
        int mid = (r- l + 1)/2;
        if(gethas_sub(1, mid, y) == gethas_subulta(l, l + mid -1, y))
            return 1;
    }
    else if(sz1 > sz2 and gethas_sub(1, sz2, x) == gethas_subulta(1,sz2,y)){
        int l = sz2 +1 , r = sz1;
        if(r - l + 1 < 2)
            return 1;
        int mid = (r- l + 1)/2;
        if(gethas_sub(l, l+mid-1, x) == gethas_subulta(1, mid , x))
            return 1;
    }
    return 0;
}


void solve(int tc)
{
    int n; cin >> n;

    pow_[0]=1;
    for(int i = 1; i<=305; i++)
        pow_[i] = (power * pow_[i-1]) % MOD;

    string a[n+2];
    for(int i = 1; i<=n ; i++){
        cin >> a[i];
        int id = i, m = a[id].size();

        for(int j = 1; j<=m; j++){
            ll val = a[id][j-1] - 'a' + 1;
            dp[id][j] = (val +  dp[id][j-1] * power) % MOD;

            ll val1 = a[id][m - j] - 'a' + 1;
            dpu[id][j] = (val1 +  dpu[id][j-1] * power) % MOD;
        }
    }

    vector<vector<int> > ans;
    for(int i = 1;i<=n; i++){
        for(int j = 1; j<=n; j++)
            if(alabu(i,j,a[i].size(), a[j].size())){
                vector<int> o({i-1,j-1});
                ans.push_back(o);
            }
    }
    for(auto i: ans){
        for(auto j: i)
            cout << j << " ";
        cout << '\n';
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

