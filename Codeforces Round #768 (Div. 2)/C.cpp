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
const ll mod = 1e9 + 7;
vector<int> a;
vector<vector<int>> go;
void dfs(int u, int &ans, vector<int> dd){
    dd[u] = 1;
    ans += a[u-1];
    for(int i = 0; i<sz(go[u]); i++)
    {
        int v = go[u][i];
        if(dd[v] == 0) dfs(v, ans, dd);
    }
}
void solve()
{
    int n, q, x, y, s, type;
    cin >> n >> q;
    vector<int> dd(n+1);
    a.resize(n);
    go.resize(n+1);
    read(a);
    for (int i = 0; i<n-1; i++){
        cin >> x >> y;
        go[x].pb(y);
    }
    for (int i = 0; i<q; i++){
        cin >> type;
        if (type == 1){
            cin >> s >> x;
            a[s-1] = x;
        }else{
            cin >> y;
            dd.resize(n + 1, 0);
            int ans = 0;
            dfs(y, ans, dd);
            cout << ans << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}