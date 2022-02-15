#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a, n) for (int i = a; i < n; i++)
#define Fd(n, a) for (int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define read(a) for (int i = 0; i<sz(a); i++) cin >> a[i]
const ll MOD = 1e9 + 7;
ll getHash(int i,int j, vector<ll> hashT, vector<ll> POW) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}
void solve() {
    int base = 31;
    string s;
    cin >> s;
    int n = sz(s);
    map<char, vector<int>> cur;
    for (int i = 0; i<n; i++){
        cur[s[i]].pb(i + 1);
    }
    vector<ll> hashT(n + 1, 0);
    vector<ll> hashP(n + 1, 0);
    vector<ll> POW(n + 1);
    string p = s;
    reverse(all(p));
    s = " " + s;
    p = " " + p;
    POW[0] = 1;
    for (int i = 1; i <= n; i++)
        POW[i] = (POW[i - 1] * base) % MOD;
    for (int i = 1; i <= n; i++){
        hashT[i] = (hashT[i - 1] * base + s[i] - 'a' + 1) % MOD;
        hashP[i] = (hashP[i - 1] * base + p[i] - 'a' + 1) % MOD;
    }
    int ans = 0;
    for (auto i: cur){
        if (sz(i.second) >= 2){
            vector<int> temp = i.second;
            for (int l = 0; l<sz(temp); l++){
                for (int r = l + 1; r<sz(temp); r++){
                    if ((temp[r] - temp[l] + 1) % 2 == 0){
                        int k = (temp[l] + temp[r])/2;
                        if (getHash(temp[l], k, hashT, POW) == getHash(n - temp[r] + 1, n - k, hashP, POW)) ans++;
                    }else{
                        int k = (temp[l] + temp[r])/2;
                        if (getHash(temp[l], k, hashT, POW) == getHash(n - temp[r] + 1, n - k + 1, hashP, POW)) ans++;
                    }
                }
            }
        }
    }
    cout << ans + n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}