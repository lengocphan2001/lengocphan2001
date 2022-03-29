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
class SegMent{
private:
    vector<ll> seg;
    ll n;
public:
    void build(vector<ll> a, ll id, ll l, ll r){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        ll mid = l + (r - l)/2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
    }
    SegMent(vector<ll> &a, int nn){
        n = nn;
        seg.resize(4 * n);
        build(a, 1, 1, n);
    }
    ll query(ll id, ll u, ll v, ll l, ll r){
        if (u > r || v < l){
            return LLONG_MAX;
        }
        if (u <= l && v >= r) return seg[id];
        ll mid = l + (r - l)/2;
        return min(query(id * 2, u, v, l, mid), query(id * 2 + 1, u, v, mid + 1, r));
    }
    ll query(ll u, ll v){
        return query(1, u, v, 1, n);
    }
};
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i<=n; i++) cin >> a[i];
    SegMent t(a, n);
    while(q--){
        ll u, v;
        cin >> u >> v;
        ll ans = t.query(u, v);
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
